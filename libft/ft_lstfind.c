/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:35:08 by mirsella          #+#    #+#             */
/*   Updated: 2023/02/12 17:37:56 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *begin_list, void *data_ref,
		int (*cmp)(void *, void *))
{
	t_list	*list;

	list = begin_list;
	while (list)
	{
		if (cmp(list->content, data_ref) == 0)
			return (list);
		list = list->next;
	}
	return (0);
}
