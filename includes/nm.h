#pragma once

#include "../libft/libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <elf.h>
#include <string.h>

typedef struct {
	unsigned int display_all;
	unsigned int display_global;
	unsigned int display_undefined;
	unsigned int no_sort;
	unsigned int reverse_sort;
} t_options;

typedef struct {
	Elf64_Sym *sym64;
	Elf64_Addr *addr64;

	Elf32_Sym *sym32;
	Elf32_Addr *addr32;
	char *name;
} t_symbol;

typedef struct {
	const char *path;
	int fd;
	struct stat stat;
	void* data;
	size_t data_size;
	t_list *symbols;
	int	elfclass;

	Elf64_Shdr *shdr64;
	Elf64_Ehdr *ehdr64;

	Elf32_Shdr *shdr32;
	Elf32_Ehdr *ehdr32;
} t_file;

// error.c
void empty_file(t_file *file);

// init_file.c
int	init_file(t_file *file);

// print_file.c
int	print_file64(t_file *file, t_options options);

// print_file.c
int	print_file32(t_file *file, t_options options);

// print_symbol.c
int	print_symbol64(t_file *file, t_symbol *symbol);
char get_type64(t_file *file, t_symbol *symbol);
