/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:31:57 by mirsella          #+#    #+#             */
/*   Updated: 2022/11/23 15:54:37 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_nbrlen(long long n)
{
	int	len;

	len = 0;
	if (n == -9223372036854775807 - 1)
		return (20);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_nbrlen_base(long long n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n == -9223372036854775807 - 1)
		return (16);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

int	ft_ullnbrlen(unsigned long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_ullnbrlen_base(unsigned long long n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base;
		len++;
	}
	return (len);
}
