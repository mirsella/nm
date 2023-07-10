/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:13:50 by mirsella          #+#    #+#             */
/*   Updated: 2023/01/05 12:42:36 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_nbrlen(int num)
{
	int	counter;

	counter = 0;
	if (num < 0)
		counter++;
	if (num == 0)
		counter++;
	while (num)
	{
		num = num / 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int value)
{
	int		len;
	int		neg;
	char	*str;

	len = ft_nbrlen(value);
	neg = 1;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len] = 0;
	len--;
	if (value < 0)
	{
		neg = -1;
		str[0] = '-';
	}
	while ((neg > 0 && len >= 0) || (neg < 0 && len > 0))
	{
		str[len] = (value % 10 * neg) + '0';
		value /= 10;
		len--;
	}
	return (str);
}
