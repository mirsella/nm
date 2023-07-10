/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:35:33 by mirsella          #+#    #+#             */
/*   Updated: 2023/07/10 15:03:22 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef struct s_list {
	void			*content;
	struct s_list	*next;
}	t_list;

int					ft_floor(double x);
int					ft_ceil(double x);
int					ft_round(double x);
int					ft_isascending(int *tab, int size);
int					ft_isdescending(int *tab, int size);
int					ft_atoi(const char *str);
long long			ft_atoll(const char *str);
int					ft_isalnum(int c);
int					ft_isspace(char c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_lstsize(t_list *lst);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_putchar(char c);
int					ft_putstr(char *s);
int					ft_putnbr(long long n);
int					ft_putnbr_base(long long n, char *base);
long long			ft_llmax(long long a, long long b);
unsigned long long	ft_ullmax(unsigned long long a, unsigned long long b);
long long			ft_llmin(long long a, long long b);
unsigned long long	ft_ullmin(unsigned long long a, unsigned long long b);
int					ft_nbrlen(long long n);
int					ft_nbrlen_base(long long n, int base);
int					ft_ullnbrlen(unsigned long long n);
int					ft_ullnbrlen_base(unsigned long long n, int base);
int					ft_abs(int n);
long long			ft_llabs(long long n);
int					ft_printf(const char *format, ...);
char				**ft_split(const char *s, const char *charset);
char				**ft_splitword(const char *s, const char *word);
char				*ft_itoa(int n);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s1, size_t n);
char				**ft_tabdup(char **tab);
char				**ft_lst_to_tab(t_list *lst);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strjoin_free(char *s1, char *s2);
int					ft_skip_spaces(char *str);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(const char *s1, const char *set);
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char				*ft_substr(const char *s, unsigned int start, size_t len);
char				*ft_get_next_line(int fd, int freee);
void				ft_free_tab(char **tab);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlen(const char *s);
size_t				ft_tablen(char **tab);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
t_list				*ft_lstfind(t_list *begin_list, void *data_ref,
						int (*cmp)(void *, void *));
t_list				*ft_lstnew(void *content);
t_list				*ft_lstnew_strs(int size, char **strs);
char				*ft_lst_to_str(t_list *lst);
t_list				*ft_lstat(t_list *begin_list, unsigned int nbr);
void				ft_lst_remove_if(t_list **begin_list, void *data_ref,
						int (*cmp)(void *, void *), void (*free_fct)(void *));
void				ft_intsort(int *tab, int size);
void				*ft_calloc(size_t count, size_t size);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				ft_lstreverse(t_list **lst);
void				ft_lstadd_back(t_list **alst, t_list *newel);
void				ft_lstsort(t_list **lst, int (*cmp)());
void				ft_lstadd_front(t_list **alst, t_list *newel);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
int					ft_putchar_fd(char c, int fd);
int					ft_putendl_fd(char *s, int fd);
int					ft_putnbr_fd(int n, int fd);
int					ft_putstr_fd(char *s, int fd);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				*ft_realloc(void *ptr, size_t ptrsize, size_t newsize);

#endif
