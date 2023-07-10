/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:56:14 by mirsella          #+#    #+#             */
/*   Updated: 2022/11/27 21:52:12 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putull_hex(t_formatoptions *fo, unsigned long long num)
{
	if (num >= 16)
	{
		ft_putull_hex(fo, num / 16);
		ft_putull_hex(fo, num % 16);
	}
	else
	{
		if (num <= 9)
			count_bytes(&fo->byteswrotes, ft_putchar(num + '0'));
		else
			count_bytes(&fo->byteswrotes, ft_putchar(num - 10 + 'a'));
	}
}

static void	ft_print_width_ullhex(t_formatoptions *fo, unsigned long long n)
{
	while (fo->width-- > ft_llmax(fo->precision, ft_ullnbrlen_base(n, 16)))
	{
		if (fo->zero)
			count_bytes(&fo->byteswrotes, ft_putchar('0'));
		else
			count_bytes(&fo->byteswrotes, ft_putchar(' '));
	}
}

static void	ft_print_ullhash(t_formatoptions *fo,
		unsigned long long n, char conversion)
{
	if (fo->hash && n != 0)
	{
		fo->width -= 2;
		if (fo->zero)
		{
			count_bytes(&fo->byteswrotes, ft_printf("0%c", conversion));
			ft_print_width_ullhex(fo, n);
		}
		else
		{
			if (fo->dash == 0)
			{
				ft_print_width_ullhex(fo, n);
			}
			count_bytes(&fo->byteswrotes, ft_printf("0%c", conversion));
		}
	}
	else if (fo->dash == 0)
		ft_print_width_ullhex(fo, n);
}

void	ft_print_pointer(t_formatoptions *fo, unsigned long long n)
{
	int	precision;

	fo->hash = 1;
	precision = fo->precision;
	if (fo->precision >= 0)
		fo->zero = 0;
	if (fo->precision == -1)
		fo->precision = 1;
	if (n == 0)
	{
		if (fo->dash == 0)
			ft_print_width_ullhex(fo, 100000);
		count_bytes(&fo->byteswrotes, ft_putstr("(nil)"));
		if (fo->dash == 1)
			ft_print_width_ullhex(fo, 100000);
	}
	else
	{
		ft_print_ullhash(fo, n, 'x');
		while (precision-- > ft_ullnbrlen_base(n, 16))
			count_bytes(&fo->byteswrotes, ft_putchar('0'));
		ft_putull_hex(fo, n);
		if (fo->dash == 1)
			ft_print_width_ullhex(fo, n);
	}
}
