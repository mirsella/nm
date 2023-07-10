/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:11:55 by mirsella          #+#    #+#             */
/*   Updated: 2022/11/27 21:53:21 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	count_bytes(int *counter, int byteswrotes)
{
	if (!counter)
		return ;
	if (byteswrotes < 0 || *counter < 0)
		*counter = -1;
	else
		*counter += byteswrotes;
}

int	ft_printf(const char *format, ...)
{
	int				i;
	int				byteswrotes;
	va_list			args;
	t_formatoptions	fo;

	i = 0;
	byteswrotes = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[++i] != '%')
		{
			ft_bzero(&fo, sizeof(t_formatoptions));
			fo.precision = -1;
			i += parse_callprinters(&fo, format + i, args);
			count_bytes(&byteswrotes, fo.byteswrotes);
		}
		else
		{
			count_bytes(&byteswrotes, ft_putchar(format[i]));
			i++;
		}
	}
	va_end(args);
	return (byteswrotes);
}
