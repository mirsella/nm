/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 00:36:30 by mirsella          #+#    #+#             */
/*   Updated: 2023/07/11 21:07:59 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_round(double x) {
	if (x > 0) {
		if (x - (int)x >= 0.5)
			return ((int)x + 1);
		else
			return ((int)x);
	} else {
		if (x - (int)x <= -0.5)
			return ((int)x - 1);
		else
			return ((int)x);
	}
}

int	ft_floor(double x) {
	if (x < (int)x)
		return ((int)x - 1);
	return x;
}

int ft_ceil(double x) {
	if (x > (int)x)
		return ((int)x + 1);
	return x;
}

int	ft_abs(int n) {
	if (n < 0)
		return (-n);
	return (n);
}

long long	ft_llabs(long long n) {
	if (n < 0)
		return (-n);
	return (n);
}
