/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:16:36 by mirsella          #+#    #+#             */
/*   Updated: 2022/11/27 21:47:42 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include "stdarg.h"
# include "stdio.h"

typedef struct s_formatoptions
{
	int	byteswrotes;
	int	width;
	int	precision;
	int	dash;
	int	zero;
	int	hash;
	int	space;
	int	plus;
}	t_formatoptions;

void	count_bytes(int *counter, int bytesrwotes);
void	ft_print_string(t_formatoptions *fo, char *s);
void	ft_print_char(t_formatoptions *fo, unsigned char c);
void	ft_print_int(t_formatoptions *fo, int n);
void	ft_print_unsigned_int(t_formatoptions *fo, unsigned int n);
void	ft_print_hex(t_formatoptions *fo, unsigned int n, char conversion);
void	ft_print_pointer(t_formatoptions *fo, unsigned long long p);
int		parse_callprinters(t_formatoptions *fo,
			const char *format, va_list args);
int		ft_printf(const char *format, ...);

#endif
