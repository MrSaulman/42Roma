/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarbant <gbarbant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:28:31 by gbarbant          #+#    #+#             */
/*   Updated: 2022/11/07 16:33:22 by gbarbant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	parse_floor(char *line, t_game *game)
{
	int	i;

	i = 1;
	i += spaceskip(line, 1);
	if (game->paths.floor.r != -1 || game->paths.floor.g != -1
		|| game->paths.floor.b != -1)
		return (1);
}

int	parse_ceiling(char *line, t_game *game)
{
	
}
