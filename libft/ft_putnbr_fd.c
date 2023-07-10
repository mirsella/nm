/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:13:50 by mirsella          #+#    #+#             */
/*   Updated: 2023/02/24 15:44:30 by mirsella         ###   ########.fr       */
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

int	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		i;

	i = 0;
	if (n == -2147483648)
		return (write(fd, "-2147483648", 11));
	if (n < 0)
	{
		if (count_bytes(&i, ft_putchar_fd('-', fd)) == -1)
			return (i);
		n = -n;
	}
	if (n > 9)
	{
		if (count_bytes(&i, ft_putnbr_fd(n / 10, fd)) == -1)
			return (i);
		count_bytes(&i, ft_putnbr_fd(n % 10, fd));
	}
	else
	{
		c = n + '0';
		count_bytes(&i, ft_putchar_fd(c, fd));
	}
	return (i);
}
