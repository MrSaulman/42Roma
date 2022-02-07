/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <asalvemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:37:23 by asalvemi          #+#    #+#             */
/*   Updated: 2022/02/04 16:37:50 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

/* Returns TRUE if the file is valid */
int	valid_file(int argc, char *file)
{
	if (argc == 1)
		return (error("No args"));
	if (argc > 2)
		print_warning("Only first argument will be used.");
	if (!ft_strend_cmp(file, ".ber"))
		return (error("You need a .ber map file"));
	return (1);
}