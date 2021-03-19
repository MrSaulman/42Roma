/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <asalvemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:13:05 by asalvemi          #+#    #+#             */
/*   Updated: 2021/03/17 19:51:01 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_check_segfault(const char *s)
{
    int     i;
    int     ok;

    i = 0;
    ok = 0;
    while(s[i])
    {
        if (ft_strchr(CONVERSIONS, s[i]))
        {
            ok = 1;
        }
        i++;
    }
    return (ok);
}

int     ft_neg_star(int num, t_flags *flags)
{
    if (flags->precision == 1)
    {
        flags->precision = 0;
        return(0);
    }
    flags->minus = 1;
    return (num * -1);
}