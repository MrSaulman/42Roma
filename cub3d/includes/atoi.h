/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <gcrocett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:52:29 by gcrocett          #+#    #+#             */
/*   Updated: 2022/07/14 14:20:41 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATOI_H
# define ATOI_H

# include <stdbool.h>

bool	is_instr(char car, char *st);
bool	cmeno(char st);
bool	iss(char car);
bool	isn(char car);
int		ft_atoi(char *str);

#endif