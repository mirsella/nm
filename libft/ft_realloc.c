/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:59:30 by mirsella          #+#    #+#             */
/*   Updated: 2023/03/04 15:59:24 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_realloc(void *ptr, size_t ptrsize, size_t newsize)
{
	void	*newptr;

	if (ptr == NULL)
		return (ft_calloc(newsize, 1));
	if (newsize == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (newsize <= ptrsize)
		return (ptr);
	newptr = ft_calloc(newsize, 1);
	if (newptr == NULL)
		return (NULL);
	ft_memcpy(newptr, ptr, ptrsize);
	free(ptr);
	return (newptr);
}
