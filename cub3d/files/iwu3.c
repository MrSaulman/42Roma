/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iwu3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <gcrocett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:52:29 by gcrocett          #+#    #+#             */
/*   Updated: 2022/08/26 17:34:05 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_utils.h"

void	rnf_color_and_dir(t_alls *sts)
{
	sts->raycast.wallx -= floor((sts->raycast.wallx));
	sts->raycast.floor_color = make_color(0, sts->floor_color.r,
			sts->floor_color.g, sts->floor_color.b);
	sts->raycast.roof_color = make_color(0, sts->ceiling_color.r,
			sts->ceiling_color.g, sts->ceiling_color.b);
	sts->raycast.step_draw = 1.0 * 32 / sts->raycast.lineheight;
	sts->raycast.wally = (sts->raycast.drawstart - sts->resolution.y
			/ 2 + sts->raycast.lineheight / 2) * sts->raycast.step_draw;
	if (sts->raycast.side && sts->move.posy > sts->raycast.mapy)
		sts->raycast.wall_dir = 0;
	else if (sts->raycast.side && sts->move.posy <= sts->raycast.mapy)
		sts->raycast.wall_dir = 1;
	else if (!sts->raycast.side && sts->move.posx > sts->raycast.mapx)
		sts->raycast.wall_dir = 2;
	else
		sts->raycast.wall_dir = 3;
}

void	rnf_calc_drawend(t_alls *sts, int i, int x)
{
	while (i < sts->raycast.drawend)
	{
		sts->raycast.texy = (int)sts->raycast.wally & (31);
		sts->raycast.wally += sts->raycast.step_draw;
		sts->raycast.wall_color = make_color(0, sts->tex.texture
			[sts->raycast.wall_dir][(int)sts->raycast.texy]
			[(int)(((sts->raycast.wallx * 100) / 3.125))].r,
				sts->tex.texture[sts->raycast.wall_dir][(int)sts->raycast.texy]
			[(int)(((sts->raycast.wallx * 100) / 3.125))].g,
				sts->tex.texture[sts->raycast.wall_dir][(int)sts->raycast.texy]
			[(int)(((sts->raycast.wallx * 100) / 3.125))].b);
		if (!sts->iniziali)
			verticalstripe(sts->image_data, x, (i * 10000 + i),
				sts->raycast.wall_color);
		else
			verticalstripe(sts->image_data, sts->resolution.x - x - 1,
				(i * 10000 + i), sts->raycast.wall_color);
		i++;
	}
}

void	rnf_print(t_alls *sts, int x)
{
	if (!sts->iniziali)
	{
		verticalstripe(sts->image_data, x, sts->raycast.drawstart,
			sts->raycast.roof_color);
		verticalstripe(sts->image_data, x,
			(sts->raycast.drawend * 10000 + 1079), sts->raycast.floor_color);
	}
	else
	{
		verticalstripe(sts->image_data, sts->resolution.x - x - 1,
			sts->raycast.drawstart, sts->raycast.roof_color);
		verticalstripe(sts->image_data, sts->resolution.x - x - 1,
			(sts->raycast.drawend * 10000 + 1079), sts->raycast.floor_color);
	}
}
