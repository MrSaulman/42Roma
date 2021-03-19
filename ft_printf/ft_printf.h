/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <asalvemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:13:24 by asalvemi          #+#    #+#             */
/*   Updated: 2021/03/19 17:04:16 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#define ALLSIMBOLS "cspdiuxX%-.*0123456789"
#define CONVERSIONS "cspdiuxX%"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "libft/libft.h"

typedef struct s_printf
{
	int     printed;
	int     minus;
	int     zero;
	int     precision;
	int     precision_l;
	int     width;
	int     negative; 
}               t_flags;

int		ft_printf(const char *format, ...);
int     ft_check_segfault(const char *s);
void    ft_reset_flags(t_flags *flags);
void 	ft_parse_str(t_flags *flags, const char *format, va_list ap, int *i);
void	ft_conversions(va_list ap, char c, t_flags *flags);
void	ft_modifiers(const char *s, int *i, t_flags *flags, va_list ap);
void	ft_chr(va_list ap, t_flags *flags);
void	ft_string(va_list ap, t_flags *flags);
void	ft_percent(t_flags *flags);
int		ft_total_digits(t_flags *flags, int digits);
void	ft_putnbr_flags(int n, t_flags *flags);
void	ft_putnbr_unsigned(unsigned int n, t_flags *flags);
void	ft_print_unsigned(va_list ap, t_flags *flags);
int		ft_zero(int n, int tot);
void	ft_int_flags(t_flags *flags, int *digits);
void	ft_print_int(va_list ap, t_flags *flags);
void	ft_getwidth(const char *s, int *i, t_flags *d, va_list ap);
void	ft_width(int width, int str_length, t_flags *flags);
int		ft_control_star(const char *s, int *i, va_list ap, t_flags *flags);
int		ft_neg_star(int num, t_flags *flags);


#endif //FT_PRINTF_H