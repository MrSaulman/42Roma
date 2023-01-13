/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iwu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <gcrocett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:52:29 by gcrocett          #+#    #+#             */
/*   Updated: 2022/08/01 16:59:56 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_utils.h"
#include <stdio.h>

static void	rnf_init(t_alls *sts, int x)
{
	sts->raycast.raydirx = sts->move.dirx + sts->move.planex
		* sts->raycast.camerax;
	sts->raycast.raydiry = sts->move.diry + sts->move.planey
		* sts->raycast.camerax;
	sts->raycast.mapx = (int)sts->move.posx;
	sts->raycast.mapy = (int)sts->move.posy;
	if (sts->raycast.raydirx == 0)
		sts->raycast.deltadistx = 1e30;
	else
		sts->raycast.deltadistx = fabs(1 / sts->raycast.raydirx);
	if (sts->raycast.raydiry == 0)
		sts->raycast.deltadisty = 1e30;
	else
		sts->raycast.deltadisty = fabs(1 / sts->raycast.raydiry);
	sts->raycast.hit = 0;
	sts->raycast.stepx = 0;
	sts->raycast.stepy = 0;
	sts->raycast.camerax = 2 * x / (double)sts->resolution.x - 1;
	sts->raycast.hit = 0;
}

static void	rnf_stepcalc(t_alls *sts)
{
	if (sts->raycast.raydirx < 0)
	{
		sts->raycast.stepx = -1;
		sts->raycast.sidedistx = (sts->move.posx - (double)sts->raycast.mapx)
			* sts->raycast.deltadistx;
	}
	else
	{
		sts->raycast.stepx = 1;
		sts->raycast.sidedistx = ((double)sts->raycast.mapx + 1.0
				- sts->move.posx) * sts->raycast.deltadistx;
	}
	if (sts->raycast.raydiry < 0)
	{
		sts->raycast.stepy = -1;
		sts->raycast.sidedisty = (sts->move.posy - (double)sts->raycast.mapy)
			* sts->raycast.deltadisty;
	}
	else
	{
		sts->raycast.stepy = 1;
		sts->raycast.sidedisty = ((double)sts->raycast.mapy + 1.0
				- sts->move.posy) * sts->raycast.deltadisty;
	}
}

static void	rnf_find_dist(t_alls *sts)
{
	while (sts->raycast.hit == 0)
	{
		if (sts->raycast.sidedistx < sts->raycast.sidedisty)
		{
			sts->raycast.sidedistx += sts->raycast.deltadistx;
			sts->raycast.mapx += sts->raycast.stepx;
			sts->raycast.side = 0;
		}
		else
		{
			sts->raycast.sidedisty += sts->raycast.deltadisty;
			sts->raycast.mapy += sts->raycast.stepy;
			sts->raycast.side = 1;
		}
		if (sts->map[sts->raycast.mapy][sts->raycast.mapx] > 48)
			sts->raycast.hit = 1;
	}
}

static void	rnf_calc_drawstart(t_alls *sts)
{
	if (sts->raycast.side == 0)
		sts->raycast.perpwalldist = (sts->raycast.sidedistx
				- sts->raycast.deltadistx);
	else
		sts->raycast.perpwalldist = (sts->raycast.sidedisty
				- sts->raycast.deltadisty);
	sts->raycast.lineheight = (int)((double)sts->resolution.y
			/ sts->raycast.perpwalldist);
	sts->raycast.drawstart = - (sts->raycast.lineheight)
		/ 2 + sts->resolution.y / 2;
	if (sts->raycast.drawstart < 0)
		sts->raycast.drawstart = 0;
	if (sts->raycast.drawstart >= sts->resolution.y)
		sts->raycast.drawstart = sts->resolution.y - 1;
	sts->raycast.drawend = sts->raycast.lineheight / 2 + sts->resolution.y / 2;
	if (sts->raycast.drawend >= sts->resolution.y)
		sts->raycast.drawend = sts->resolution.y - 1;
	if (sts->raycast.drawend < 0)
		sts->raycast.drawend = 0;
	if (sts->raycast.side == 0)
		sts->raycast.wallx = sts->move.posy + sts->raycast.perpwalldist
			* sts->raycast.raydiry;
	else
		sts->raycast.wallx = sts->move.posx + sts->raycast.perpwalldist
			* sts->raycast.raydirx;
}

int	render_next_frame(t_alls *sts)
{
	int	x;
	int	i;

	x = 0;
	while (x < sts->resolution.x)
	{
		rnf_init(sts, x);
		rnf_stepcalc(sts);
		rnf_find_dist(sts);
		rnf_calc_drawstart(sts);
		rnf_color_and_dir(sts);
		i = sts->raycast.drawstart;
		rnf_calc_drawend(sts, i, x);
		rnf_print(sts, x);
		x++;
	}
	mlx_put_image_to_window(sts->wndw.mlx_image, sts->wndw.mlx_windows,
		sts->image_data->image, 0, 0);
	return (0);
}
