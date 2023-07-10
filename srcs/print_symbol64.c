#include "../includes/nm.h"

char get_type64(t_file *file, t_symbol *symbol) {
	char c;

	if (ELF64_ST_BIND(symbol->sym64->st_info) == STB_GNU_UNIQUE)
		c = 'u';
	else if (ELF64_ST_BIND(symbol->sym64->st_info) == STB_WEAK) {
		c = 'W';
		if (symbol->sym64->st_shndx == SHN_UNDEF)
			c = 'w';
	} else if (ELF64_ST_BIND(symbol->sym64->st_info)
			== STB_WEAK && ELF64_ST_TYPE(symbol->sym64->st_info) == STT_OBJECT) {
		c = 'V';
		if (symbol->sym64->st_shndx == SHN_UNDEF)
			c = 'v';
	} else if (symbol->sym64->st_shndx == SHN_UNDEF)
		c = 'U';
	else if (symbol->sym64->st_shndx == SHN_ABS)
		c = 'A';
	else if (symbol->sym64->st_shndx == SHN_COMMON)
		c = 'C';
	else if (file->shdr64[symbol->sym64->st_shndx].sh_type == SHT_NOBITS
			&& file->shdr64[symbol->sym64->st_shndx].sh_flags ==
			(SHF_ALLOC | SHF_WRITE))
		c = 'B';
	else if (file->shdr64[symbol->sym64->st_shndx].sh_type == SHT_PROGBITS
			&& file->shdr64[symbol->sym64->st_shndx].sh_flags == SHF_ALLOC)
		c = 'R';
	else if (file->shdr64[symbol->sym64->st_shndx].sh_type == SHT_PROGBITS
			&& file->shdr64[symbol->sym64->st_shndx].sh_flags ==
			(SHF_ALLOC | SHF_WRITE))
		c = 'D';
	else if (file->shdr64[symbol->sym64->st_shndx].sh_type == SHT_PROGBITS
			&& file->shdr64[symbol->sym64->st_shndx].sh_flags ==
			(SHF_ALLOC | SHF_EXECINSTR))
		c = 'T';
	else if (file->shdr64[symbol->sym64->st_shndx].sh_type == SHT_DYNAMIC)
		c = 'D';
	else
		c = ('t' - 32);

	if (ELF64_ST_BIND(symbol->sym64->st_info) == STB_LOCAL && c != '?')
		c += 32;
	return (c);
}

int	print_symbol64(t_file *file, t_symbol *symbol) {
	char type = get_type64(file, symbol);
	if (*symbol->addr64 == 0 && (type == 'U' || type == 'u' || type =='w' || type == 'W'))
		ft_printf("%16c", ' ');
	else
		ft_printf("%016x", *symbol->addr64);
	ft_printf(" %c ", type);
	ft_printf("%s\n", symbol->name);
	return 0;
}

