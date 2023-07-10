/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:57:21 by mirsella          #+#    #+#             */
/*   Updated: 2022/12/08 15:03:57 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_llmax(long long a, long long b)
{
	if (a > b)
		return (a);
	return (b);
}

unsigned long long	ft_ullmax(unsigned long long a, unsigned long long b)
{
	if (a > b)
		return (a);
	return (b);
}

long long	ft_llmin(long long a, long long b)
{
	if (a < b)
		return (a);
	return (b);
}

unsigned long long	ft_ullmin(unsigned long long a, unsigned long long b)
{
	if (a < b)
		return (a);
	return (b);
}
