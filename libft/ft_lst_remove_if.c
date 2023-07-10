/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_remove_if.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:13:28 by mirsella          #+#    #+#             */
/*   Updated: 2023/02/07 23:16:55 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lst_remove_if(t_list **begin_list, void *data_ref,
		int (*cmp)(void *, void *), void (*free_fct)(void *))
{
	t_list	*current;
	t_list	*next;

	current = *begin_list;
	if (current && cmp(current->content, data_ref) == 0)
	{
		next = current->next;
		free_fct(current->content);
		free(current);
		current = next;
	}
	*begin_list = current;
	while (current && current->next)
	{
		if (cmp(current->next->content, data_ref) == 0)
		{
			next = current->next->next;
			free_fct(current->next->content);
			free(current->next);
			current->next = next;
		}
		else
			current = current->next;
	}
}
