/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:54:36 by mirsella          #+#    #+#             */
/*   Updated: 2023/02/14 11:47:43 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

t_list	*ft_lstnew_strs(int size, char **strs)
{
	t_list	*l;
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = 0;
	l = 0;
	while (i < size)
	{
		l = ft_lstnew(strs[i]);
		if (!l)
		{
			ft_lstclear(&tmp, free);
			return (NULL);
		}
		l->next = tmp;
		tmp = l;
		i++;
	}
	return (l);
}

char	**ft_lst_to_tab(t_list *lst)
{
	char	**tab;
	int		i;

	i = ft_lstsize(lst);
	if (i == 0)
		return (NULL);
	tab = malloc(sizeof(char *) * (i + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (lst)
	{
		tab[i] = ft_strdup(lst->content);
		if (!tab[i])
		{
			ft_free_tab(tab);
			return (NULL);
		}
		lst = lst->next;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

char	*ft_lst_to_str(t_list *lst)
{
	char	*str;
	size_t	size;
	t_list	*tmp;

	if (!lst)
		return (ft_strdup(""));
	size = 0;
	tmp = lst;
	while (tmp)
	{
		size += ft_strlen(tmp->content);
		tmp = tmp->next;
	}
	str = ft_calloc(sizeof(char), size + 1);
	if (!str)
		return (NULL);
	while (lst)
	{
		ft_strlcat(str, lst->content, size + 1);
		lst = lst->next;
	}
	return (str);
}
