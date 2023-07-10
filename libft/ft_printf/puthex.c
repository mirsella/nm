/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:20:35 by mirsella          #+#    #+#             */
/*   Updated: 2022/11/27 21:51:45 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_width_hex(t_formatoptions *fo, long long n)
{
	while ((long long)fo->width-- > ft_llmax(fo->precision,
			ft_nbrlen_base(ft_llabs(n), 16)))
	{
		if (fo->zero)
			count_bytes(&fo->byteswrotes, ft_putchar('0'));
		else
			count_bytes(&fo->byteswrotes, ft_putchar(' '));
	}
}

static void	ft_print_hash(t_formatoptions *fo, long long n, char conversion)
{
	if (fo->hash && n != 0)
	{
		fo->width -= 2;
		if (fo->zero)
		{
			count_bytes(&fo->byteswrotes, ft_printf("0%c", conversion));
			ft_print_width_hex(fo, n);
		}
		else
		{
			if (fo->dash == 0)
			{
				ft_print_width_hex(fo, n);
			}
			count_bytes(&fo->byteswrotes, ft_printf("0%c", conversion));
		}
	}
	else if (fo->dash == 0)
		ft_print_width_hex(fo, n);
}

void	ft_print_hex(t_formatoptions *fo, unsigned int n, char conversion)
{
	int	precision;

	precision = fo->precision;
	if (fo->precision == 0 && n == 0)
	{
		while (fo->width-- > 0)
			count_bytes(&fo->byteswrotes, ft_putchar(' '));
		return ;
	}
	if (fo->precision >= 0)
		fo->zero = 0;
	ft_print_hash(fo, n, conversion);
	while (precision-- > ft_nbrlen_base(ft_llabs(n), 16))
		count_bytes(&fo->byteswrotes, ft_putchar('0'));
	if (conversion == 'x')
		count_bytes(&fo->byteswrotes, ft_putnbr_base(n, "0123456789abcdef"));
	else
		count_bytes(&fo->byteswrotes, ft_putnbr_base(n, "0123456789ABCDEF"));
	if (fo->dash == 1)
		ft_print_width_hex(fo, n);
}
