/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:13:50 by mirsella          #+#    #+#             */
/*   Updated: 2023/02/24 15:46:47 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int	count_bytes(int *counter, int byteswrotes)
{
	if (!counter)
		return (0);
	if (byteswrotes < 0 || *counter < 0)
		*counter = -1;
	else
		*counter += byteswrotes;
	return (byteswrotes);
}

int	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (count_bytes(&i, ft_putstr_fd(s, fd)) == -1)
		return (-1);
	count_bytes(&i, ft_putchar_fd('\n', fd));
	return (i);
}
