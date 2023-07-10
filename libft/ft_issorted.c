/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:23:30 by mirsella          #+#    #+#             */
/*   Updated: 2023/01/02 17:26:19 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascending(int *tab, int length)
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (tab[i] > tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_isdescending(int *tab, int length)
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (tab[i] < tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}
