#include "../includes/nm.h"

int	parse_argv(t_options *options, t_list **files, int argc, char **argv) {
	for (int i = 1; i < argc; ++i) {
		if (ft_strncmp(argv[i], "-a\0", ft_strlen(argv[i]) + 1) == 0)
			options->display_all = 1;
		else if (ft_strncmp(argv[i], "-g\0", ft_strlen(argv[i]) + 1) == 0)
			options->display_global = 1;
		else if (ft_strncmp(argv[i], "-u\0", ft_strlen(argv[i]) + 1) == 0)
			options->display_undefined = 1;
		else if (ft_strncmp(argv[i], "-p\0", ft_strlen(argv[i]) + 1) == 0)
			options->no_sort = 1;
		else if (ft_strncmp(argv[i], "-r\0", ft_strlen(argv[i]) + 1) == 0)
			options->reverse_sort = 1;
		else {
			t_list *new = ft_lstnew(argv[i]);
			if (!new)
				return ft_putstr("memory allocation failed\n"), -1;
			ft_lstadd_back(files, new);
		}
	}
	if (!*files) {
		t_list *new = ft_lstnew("a.out");
		if (!new)
			return ft_putstr("memory allocation failed\n"), -1;
		*files = new;
	}
	return 0;
}

int main(int argc, char* argv[]) {
	t_options options;
	ft_bzero(&options, sizeof(t_options));
	t_list *files = NULL;
	if (parse_argv(&options, &files, argc, argv) != 0)
		return EXIT_FAILURE;

	t_file file;
	int ret;
	for (int i = 0; i < ft_lstsize(files); ++i) {
		bzero(&file, sizeof(t_file));
		file.path = ft_lstat(files, i)->content;
		ret = init_file(&file);
		if (ret > 0) {
			empty_file(&file);
			continue;
		} else if (ret < 0) {
			empty_file(&file);
			break;
		}
		ret = 0;
		if (file.elfclass == ELFCLASS32)
			ret = print_file32(&file, options);
		else if (file.elfclass == ELFCLASS64)
			ret = print_file64(&file, options);
		if (ret > 0) {
			empty_file(&file);
			continue;
		} else if (ret < 0) {
			empty_file(&file);
			break;
		}
		empty_file(&file);
	}
	ft_lstclear(&files, NULL);
	return 0;
}
