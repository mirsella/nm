/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:40:14 by mirsella          #+#    #+#             */
/*   Updated: 2023/07/09 18:27:24 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static void	count_bytes(int *counter, int byteswrotes)
{
	if (!counter)
		return ;
	if (byteswrotes < 0 || *counter < 0)
		*counter = -1;
	else
		*counter += byteswrotes;
}

int	ft_putnbr(long long n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		count_bytes(&i, write(1, "-", 1));
		n = -n;
	}
	if (n > 9)
	{
		count_bytes(&i, ft_putnbr(n / 10));
		count_bytes(&i, ft_putnbr(n % 10));
	}
	else
	{
		count_bytes(&i, ft_putchar(n + '0'));
	}
	return (i);
}

static int	ft_isbase(char *base)
{
	int	j;
	int	i;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-'
			|| (base[i] < 32 || base[i] > 126))
			return (0);
		j = 0;
		while (base[j] != '\0')
		{
			if (base[j] == base[i] && j != i)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_putnbr_base(long long nbr, char *base)
{
	int			baselen;
	int			byteswrotes;
	long long	nb;

	baselen = ft_strlen(base);
	byteswrotes = 0;
	nb = nbr;
	if (!ft_isbase(base))
		return (0);
	if (nbr < 0)
	{
		count_bytes(&byteswrotes, write(1, "-", 1));
		nb = -nb;
	}
	if (nb >= baselen)
		count_bytes(&byteswrotes, ft_putnbr_base(nb / baselen, base));
	count_bytes(&byteswrotes, write(1, &base[nb % baselen], 1));
	return (byteswrotes);
}
