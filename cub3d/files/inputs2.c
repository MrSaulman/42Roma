/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:09:01 by gcrocett          #+#    #+#             */
/*   Updated: 2022/07/30 17:50:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_utils.h"

void	on_w(t_alls *sts)
{
	if (sts->map[(int)(sts->move.posy)]
		[(int)(sts->move.posx + sts->move.dirx * MSPD)] == '0')
		sts->move.posx += sts->move.dirx * MSPD;
	if (sts->map[(int)(sts->move.posy + sts->move.diry * MSPD)]
		[(int)(sts->move.posx)] == '0')
		sts->move.posy += sts->move.diry * MSPD;
}

void	on_s(t_alls *sts)
{
	if (sts->map[(int)(sts->move.posy)]
		[(int)(sts->move.posx - sts->move.dirx * MSPD)] == '0')
		sts->move.posx -= sts->move.dirx * MSPD;
	if (sts->map[(int)(sts->move.posy - sts->move.diry * MSPD)]
		[(int)(sts->move.posx)] == '0')
		sts->move.posy -= sts->move.diry * MSPD;
}

void	on_a(t_alls *sts)
{
	if (sts->map[(int)(sts->move.posy)]
		[(int)(sts->move.posx + sts->move.diry * MSPD)] == '0')
		sts->move.posx += sts->move.diry * MSPD;
	if (sts->map[(int)(sts->move.posy - sts->move.dirx * MSPD)]
		[(int)(sts->move.posx)] == '0')
		sts->move.posy -= sts->move.dirx * MSPD;
}

void	on_d(t_alls *sts)
{
	if (sts->map[(int)(sts->move.posy)]
		[(int)(sts->move.posx - sts->move.diry * MSPD)] == '0')
		sts->move.posx -= sts->move.diry * MSPD;
	if (sts->map[(int)(sts->move.posy + sts->move.dirx * MSPD)]
		[(int)(sts->move.posx)] == '0')
		sts->move.posy += sts->move.dirx * MSPD;
}
