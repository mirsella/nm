#include "../includes/nm.h"

int	init_file(t_file *file) {
	int fd = open(file->path, O_RDONLY);
	if (fd == -1)
		return ft_printf("open: '%s': can't open file\n"), 1;

	struct stat file_stat;
	if (fstat(fd, &file_stat) == -1) {
		ft_printf("fstat: '%s': can't stat file\n");
		return 1;
	}
	if (file_stat.st_size < (off_t)sizeof(Elf32_Ehdr))
		return ft_printf("'%s': file too small to be ELF"), 1;
	file->fd = fd;

	file->data = mmap(NULL, file_stat.st_size, PROT_READ, MAP_SHARED, fd, 0);
	if (file->data == MAP_FAILED || !file->data) {
		ft_printf("mmap: '%s': can't map file\n");
		return 1;
	}

	Elf64_Ehdr* elf_header = (Elf64_Ehdr*)file->data;
	if (elf_header->e_ident[EI_MAG0] != ELFMAG0 ||
		elf_header->e_ident[EI_MAG1] != ELFMAG1 ||
		elf_header->e_ident[EI_MAG2] != ELFMAG2 ||
		elf_header->e_ident[EI_MAG3] != ELFMAG3) {
		ft_printf("'%s': invalid ELF file\n", file->path);
		return 1;
	}
	if (elf_header->e_ident[EI_CLASS] == ELFCLASS32) 
		file->elfclass = ELFCLASS32;
	else if (elf_header->e_ident[EI_CLASS] == ELFCLASS64)
		file->elfclass = ELFCLASS64;
	else {
		ft_printf("'%s': invalid ELF class\n", file->path);
		return 1;
	}
	return 0;
}
