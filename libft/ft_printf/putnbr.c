/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:19:10 by mirsella          #+#    #+#             */
/*   Updated: 2022/11/27 21:51:45 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_width(t_formatoptions *fo, long n)
{
	while (fo->width-- > ft_llmax(fo->precision, ft_nbrlen(ft_llabs(n))))
	{
		if (fo->zero)
			count_bytes(&fo->byteswrotes, ft_putchar('0'));
		else
			count_bytes(&fo->byteswrotes, ft_putchar(' '));
	}
}

static void	ft_print_sign(t_formatoptions *fo, long n)
{
	if (n < 0)
		count_bytes(&fo->byteswrotes, ft_putchar('-'));
	else if (fo->plus)
		count_bytes(&fo->byteswrotes, ft_putchar('+'));
	else if (fo->space)
		count_bytes(&fo->byteswrotes, ft_putchar(' '));
}

void	ft_print_int(t_formatoptions *fo, int n)
{
	int	precision;

	precision = fo->precision;
	if (n == 0 && fo->precision == 0)
	{
		ft_print_width(fo, 0);
		return ;
	}
	if (fo->precision >= 0)
		fo->zero = 0;
	if (fo->precision == -1)
		fo->precision = 1;
	if ((fo->plus || fo->space) || n < 0)
		fo->width--;
	if (fo->dash == 0 && fo->zero == 0)
		ft_print_width(fo, n);
	ft_print_sign(fo, n);
	if (fo->dash == 0 && fo->zero == 1)
		ft_print_width(fo, n);
	while (precision-- > ft_nbrlen(ft_llabs(n)))
		count_bytes(&fo->byteswrotes, ft_putchar('0'));
	count_bytes(&fo->byteswrotes, ft_putnbr(ft_llabs(n)));
	if (fo->dash == 1)
		ft_print_width(fo, n);
}

void	ft_print_unsigned_int(t_formatoptions *fo, unsigned int n)
{
	int	precision;

	precision = fo->precision;
	if (n == 0 && fo->precision == 0)
	{
		ft_print_width(fo, 0);
		return ;
	}
	if (fo->precision >= 0)
		fo->zero = 0;
	if (fo->dash == 0 && fo->zero == 0)
		ft_print_width(fo, n);
	if (fo->dash == 0 && fo->zero == 1)
		ft_print_width(fo, n);
	while (precision-- > ft_nbrlen(ft_llabs(n)))
		count_bytes(&fo->byteswrotes, ft_putchar('0'));
	count_bytes(&fo->byteswrotes, ft_putnbr(ft_llabs(n)));
	if (fo->dash == 1)
		ft_print_width(fo, n);
}
