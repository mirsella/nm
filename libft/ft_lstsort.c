/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 09:47:15 by mirsella          #+#    #+#             */
/*   Updated: 2023/02/13 11:12:11 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsort(t_list **lst, int (*cmp)(void *, void *))
{
	t_list	*tmp;
	t_list	*tmp2;
	void	*content;

	tmp = *lst;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (cmp(tmp->content, tmp2->content) > 0)
			{
				content = tmp->content;
				tmp->content = tmp2->content;
				tmp2->content = content;
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}
