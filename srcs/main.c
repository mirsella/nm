#include "../includes/nm.h"

int	parse_argv(t_options *options, t_list **files, int argc, char **argv) {
  for (int i = 1; i < argc; ++i) {
    if (argv[i][0] == '-' && argv[i][1]) {
      while (*(++argv[i])) {
        if (*argv[i] == 'a')
          options->display_all = true;
        else if (*argv[i] == 'g')
          options->display_global = true;
        else if (*argv[i] == 'u')
          options->display_undefined = true;
        else if (*argv[i] == 'p')
          options->no_sort = true;
        else if (*argv[i] == 'r')
          options->reverse_sort = true;
        else
          return ft_printf("usage: %s [-a] [-g] [-u] [-p] [-r] [file ...]\n", argv[0]), 1;
      }
    } else {
      if (*files)
        options->print_file_name = true;
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
      ret = print_file32(&file, &options);
    else if (file.elfclass == ELFCLASS64)
      ret = print_file64(&file, &options);
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
