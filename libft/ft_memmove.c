/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:13:50 by mirsella          #+#    #+#             */
/*   Updated: 2022/11/10 19:17:01 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stddef.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*ssrc;
	unsigned char		*ddest;

	if (!dest || !src)
		return (NULL);
	ssrc = src;
	ddest = dest;
	if (dest > src)
	{
		while (n--)
			ddest[n] = ssrc[n];
	}
	else
	{
		while (n--)
			*ddest++ = *ssrc++;
	}
	return (dest);
}
