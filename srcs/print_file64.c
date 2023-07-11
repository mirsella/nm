#include "../includes/nm.h"

// nm sort alphabetically, skipping _, and case insensitive
int compare_symbol64(void *a, void *b) {
	t_symbol *symbol_a = a;
	t_symbol *symbol_b = b;
	const char *s1 = symbol_a->name;
	const char *s2 = symbol_b->name;

	if (s1 == NULL || s2 == NULL)
		return (0);
	while (*s1 && *s2) {
		while (*s1 && !ft_isalnum(*s1))
			s1++;
		while (*s2 && !ft_isalnum(*s2))
			s2++;
		if (ft_tolower(*s1) != ft_tolower(*s2))
			return ((unsigned char) ft_tolower(*s1) - (unsigned char) ft_tolower(*s2));
		s1++;
		s2++;
	}
	return ((unsigned char) *s1 - (unsigned char) *s2);
}

int	print_symbols64(t_file *file, t_options options) {
	(void)options;
	t_list *symbols = file->symbols;
	while (symbols) {
		t_symbol *symbol = symbols->content;
		if (print_symbol64(file, symbol) < 0)
				return -1;
		symbols = symbols->next;
	}
	return 0;
}

int	print_file64(t_file *file, t_options options) {
	(void)options;

	Elf64_Ehdr *header = file->data;
	file->ehdr64 = header;
	if (header->e_shoff > (size_t)file->stat.st_size)
		return ft_printf("'%s': error e_shoff bigger than file size\n", file->path), 1;
	Elf64_Shdr *sections = file->data + header->e_shoff;
	file->shdr64 = sections;
	if (sections->sh_size != 0 && sections->sh_offset != 0)
		return ft_printf("'%s': error bad section\n", file->path), 1;
	if (header->e_shstrndx >= header->e_shnum || sections[header->e_shstrndx].sh_type != SHT_STRTAB)
		return ft_printf("'%s': error bad section header\n", file->path), 1;


	Elf64_Shdr *symtab_section = NULL;
	Elf64_Shdr *strtab_section = NULL;
	for (int i = 0; i < header->e_shnum; ++i) {
		if (sections[i].sh_name > sections[header->e_shstrndx].sh_size)
			return ft_printf("'%s': error bad section header at %d\n", file->path, i), 1;
		if (sections[i].sh_type == SHT_SYMTAB) {
			symtab_section = &sections[i];
			strtab_section = &sections[sections[i].sh_link];
			break;
		}
	}
	if (symtab_section == NULL || strtab_section == NULL)
		return ft_printf("'%s': no symbol table found\n", file->path), 1;

	Elf64_Sym *symbol_table = file->data + symtab_section->sh_offset;
	char	*strtab = file->data + strtab_section->sh_offset;
	for (int i = 0; i < ft_ceil((double)symtab_section->sh_size / (double)sizeof(Elf64_Sym)); ++i) {

		uint16_t st_shndx = symbol_table[i].st_shndx;
		Elf64_Sym *sym = &symbol_table[i];
		if (!sym->st_info && !sym->st_value)
			continue; // no name and address
		if (options.display_undefined && st_shndx == SHN_UNDEF) {} // don't show undefined symbol without -u
		else if (options.display_global && (ELF64_ST_BIND(sym->st_info) == STB_GLOBAL || ELF64_ST_BIND(sym->st_info) == STB_WEAK)) {}  // don't show global symbol without -g
		else if (options.display_all) {}
		else if (!(st_shndx == SHN_LOPROC || st_shndx == SHN_BEFORE || st_shndx == SHN_AFTER ||
				st_shndx == SHN_HIPROC || st_shndx == SHN_LOOS || st_shndx == SHN_HIOS ||
				st_shndx == SHN_ABS || st_shndx == SHN_COMMON || st_shndx == SHN_XINDEX ||
				st_shndx == SHN_HIRESERVE) && ELF64_ST_TYPE(sym->st_info) != STT_SECTION) {}
		else
			continue;

		t_symbol *symbol = malloc(sizeof(t_symbol));
		if (!symbol)
			return ft_putstr("memory allocation failed\n"), -1;
		bzero(symbol, sizeof(t_symbol));
		symbol->sym64 = sym;
		symbol->addr64 = &symbol_table[i].st_value;
		symbol->name = strtab + symbol_table[i].st_name;
		if (symbol_table[i].st_shndx < header->e_shnum) {
			if (ELF64_ST_TYPE(symbol_table[i].st_info) == STT_SECTION)
				symbol->name = (file->data + sections[header->e_shstrndx].sh_offset) + sections[symbol_table[i].st_shndx].sh_name;
		}
		t_list *new = ft_lstnew(symbol);
		if (!new)
			return ft_putstr("memory allocation failed\n"), -1;
		ft_lstadd_back(&file->symbols, new);
	}

	if (!options.no_sort)
		ft_lstsort(&file->symbols, &compare_symbol64);
	if (!options.no_sort && options.reverse_sort)
		ft_lstreverse(&file->symbols);
	if (print_symbols64(file, options) < 0)
		return -1;
	return 0;
}
