/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <gcrocett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:09:01 by gcrocett          #+#    #+#             */
/*   Updated: 2022/08/02 17:13:36 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_utils.h"

void	on_left(t_alls *sts)
{
	double	olddirx;
	double	oldplanex;

	oldplanex = sts->move.planex;
	olddirx = sts->move.dirx;
	sts->move.dirx = sts->move.dirx * cos(-RSPD) - sts->move.diry * sin(-RSPD);
	sts->move.diry = olddirx * sin(-RSPD) + sts->move.diry * cos(-RSPD);
	sts->move.planex = sts->move.planex * cos(-RSPD)
		- sts->move.planey * sin(-RSPD);
	sts->move.planey = oldplanex * sin(-RSPD) + sts->move.planey * cos(-RSPD);
}

void	on_right(t_alls *sts)
{
	double	olddirx;
	double	oldplanex;

	olddirx = sts->move.dirx;
	oldplanex = sts->move.planex;
	sts->move.dirx = sts->move.dirx * cos(RSPD) - sts->move.diry * sin(RSPD);
	sts->move.diry = olddirx * sin(RSPD) + sts->move.diry * cos(RSPD);
	sts->move.planex = sts->move.planex * cos(RSPD)
		- sts->move.planey * sin(RSPD);
	sts->move.planey = oldplanex * sin(RSPD) + sts->move.planey * cos(RSPD);
}

int	my_destroy(t_alls *sts)
{
	if (sts)
	{
		printf("self destruct sequence initiated: 3... 2... 1...\n");
		mlx_destroy_window(sts->wndw.mlx_image, sts->wndw.mlx_windows);
		ft_my_free(sts);
	}
	exit(0);
}

int	my_keys(int keycode, t_alls *sts)
{
	if (sts)
	{
		if (keycode == 13)
			on_w(sts);
		else if (keycode == 0)
			on_a(sts);
		else if (keycode == 1)
			on_s(sts);
		else if (keycode == 2)
			on_d(sts);
		else if (keycode == 123)
			on_left(sts);
		else if (keycode == 124)
			on_right(sts);
		else if (keycode == 53)
			my_destroy(sts);
	}
	return (0);
}
