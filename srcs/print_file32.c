#include "../includes/nm.h"
#include <elf.h>

int	print_symbols32(t_file *file, t_options *options) {
  t_list *symbols = file->symbols;
  if (options->print_file_name)
    ft_printf("\n%s:\n", file->path);
  while (symbols) {
    t_symbol *symbol = symbols->content;
    if (symbol->sym32->st_shndx == SHN_UNDEF)
      ft_printf("%8c %c %s\n", ' ', symbol->type, symbol->name);
    else
      ft_printf("%08x %c %s\n", symbol->sym32->st_value, symbol->type, symbol->name);
    symbols = symbols->next;
  }
  return 0;
}

int	print_file32(t_file *file, t_options *options) {
  Elf32_Ehdr *header = file->data;
  file->ehdr32 = header;
  if (header->e_shoff > (size_t)file->stat.st_size)
    return ft_printf("'%s': error e_shoff bigger than file size\n", file->path), 1;
  Elf32_Shdr *sections = file->data + header->e_shoff;
  file->shdr32 = sections;
  if (sections->sh_size != 0 && sections->sh_offset != 0)
    return ft_printf("'%s': error bad section\n", file->path), 1;
  if (header->e_shstrndx >= header->e_shnum || sections[header->e_shstrndx].sh_type != SHT_STRTAB)
    return ft_printf("'%s': error bad section header\n", file->path), 1;


  Elf32_Shdr *symtab_section = NULL;
  Elf32_Shdr *strtab_section = NULL;
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

  Elf32_Sym *symbol_table = file->data + symtab_section->sh_offset;
  char	*strtab = file->data + strtab_section->sh_offset;
  for (int i = 1; i < ft_ceil((double)symtab_section->sh_size / (double)sizeof(Elf32_Sym)); ++i) {

    uint16_t st_shndx = symbol_table[i].st_shndx;
    Elf32_Sym *sym = &symbol_table[i];
    /* printf("%016lx %02x %02x %04x %04lx %02x %s\n", sym->st_value, sym->st_info, sym->st_other, sym->st_shndx, sym->st_size, sym->st_name, strtab + sym->st_name); */

    int skipping = 1;
    if (options->display_undefined) {
      if (st_shndx == SHN_UNDEF)
        skipping = 0;
    } else if (options->display_global) {
      if (ELF32_ST_BIND(sym->st_info) == STB_GLOBAL || ELF32_ST_BIND(sym->st_info) == STB_WEAK)
        skipping = 0;
    } else if (options->display_all) {
      skipping = 0;
    } else if (!(st_shndx == SHN_LOPROC || st_shndx == SHN_BEFORE || st_shndx == SHN_AFTER ||
        st_shndx == SHN_HIPROC || st_shndx == SHN_LOOS || st_shndx == SHN_HIOS ||
        st_shndx == SHN_ABS || st_shndx == SHN_COMMON || st_shndx == SHN_XINDEX ||
        st_shndx == SHN_HIRESERVE) && ELF32_ST_TYPE(sym->st_info) != STT_SECTION) {
      skipping = 0;
    } else if (ELF64_ST_BIND(sym->st_info) == STB_GLOBAL)
      skipping = 0;

    if (skipping == 1) {
      /* printf("skipping %s, st_shndx %d, st_type %d, bind %d\n", strtab + sym->st_name, st_shndx, ELF32_ST_TYPE(sym->st_info), ELF32_ST_BIND(sym->st_info)); */
      continue;
    }

    t_symbol *symbol = malloc(sizeof(t_symbol));
    if (!symbol)
      return ft_putstr("memory allocation failed\n"), -1;
    bzero(symbol, sizeof(t_symbol));
    symbol->sym32 = sym;
    symbol->name = strtab + symbol_table[i].st_name;
    symbol->index = st_shndx;
    if (sym->st_shndx < header->e_shnum) {
      if (ELF32_ST_TYPE(sym->st_info) == STT_SECTION)
        symbol->name = (file->data + sections[header->e_shstrndx].sh_offset) + sections[sym->st_shndx].sh_name;
    }
    symbol->type = get_type32(file, symbol);
    t_list *new = ft_lstnew(symbol);
    if (!new)
      return ft_putstr("memory allocation failed\n"), -1;
    ft_lstadd_back(&file->symbols, new);
  }

  if (!options->no_sort) {
    ft_lstsort(&file->symbols, &compare_value);
    ft_lstsort(&file->symbols, &compare_symbol);
    if (options->reverse_sort)
      ft_lstreverse(&file->symbols);
  }
  if (print_symbols32(file, options) < 0)
    return -1;
  return 0;
}
