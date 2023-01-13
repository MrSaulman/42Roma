/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <gcrocett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:46:46 by gcrocett          #+#    #+#             */
/*   Updated: 2022/08/03 17:36:45 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_utils.h"

static void	initial_posrot_help(t_alls *sts)
{
	sts->move.dirx = 0;
	sts->move.diry = 0;
	sts->move.planex = 0;
	sts->move.planey = 0;
	sts->iniziali = 0;
	sts->move.posx = sts->spawn_pos.x + 0.5;
	sts->move.posy = sts->spawn_pos.y + 0.5;
}

void	initial_posrot(t_alls *sts)
{
	initial_posrot_help(sts);
	if (sts->spawn_dir == 'W')
	{
		sts->move.dirx = -1;
		sts->move.planey = 0.66;
		sts->iniziali = 1;
	}
	if (sts->spawn_dir == 'E')
	{
		sts->move.dirx = 1;
		sts->move.planey = 0.66;
	}
	if (sts->spawn_dir == 'N')
	{
		sts->move.diry = -1;
		sts->move.planex = 0.66;
	}
	if (sts->spawn_dir == 'S')
	{
		sts->move.diry = 1;
		sts->move.planex = 0.66;
		sts->iniziali = 1;
	}
}
