/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <gcrocett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:57:39 by gcrocett          #+#    #+#             */
/*   Updated: 2022/08/26 17:28:16 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_utils.h"

static void	ft_my_free_utils(t_alls *sts)
{
	int	i;

	i = 0;
	while (i < sts->tex_file.nr)
		my_free(sts->tex_file.north[i++], "ft_my_free", 1);
	my_free(sts->tex_file.north, "ft_my_free", 1);
	i = 0;
	while (i < sts->tex_file.sr)
		my_free(sts->tex_file.south[i++], "ft_my_free", 1);
	my_free(sts->tex_file.south, "ft_my_free", 1);
	i = 0;
	while (i < sts->tex_file.wr)
		my_free(sts->tex_file.west[i++], "ft_my_free", 1);
	my_free(sts->tex_file.west, "ft_my_free", 1);
	i = 0;
	while (i < sts->tex_file.er)
		my_free(sts->tex_file.east[i++], "ft_my_free", 1);
	my_free(sts->tex_file.east, "ft_my_free", 1);
}

void	ft_my_free(t_alls *sts)
{
	int	i;

	if (sts->image_data)
		my_free(sts->image_data->image, "ft_my_free", 1);
	if (sts->image_data)
		my_free(sts->image_data->address, "ft_my_free", 1);
	my_free(sts->image_data, "ft_my_free", 1);
	my_free(sts->paths.n_path, "ft_my_free", 1);
	my_free(sts->paths.s_path, "ft_my_free", 1);
	my_free(sts->paths.w_path, "ft_my_free", 1);
	my_free(sts->paths.e_path, "ft_my_free", 1);
	my_free(sts->paths.sprite_path, "ft_my_free", 1);
	i = -1;
	if (sts->map)
		while (sts->map[++i])
			my_free(sts->map[i], "ft_my_free", 1);
	i = -1;
	if (sts->map_checker)
		while (sts->map_checker[++i])
			my_free(sts->map_checker[i], "ft_my_free", 1);
	my_free(sts->map, "ft_my_free", 1);
	my_free(sts->map_checker, "ft_my_free", 1);
	ft_my_free_utils(sts);
	my_free(sts, "ft_my_free", 1);
}

void	my_free(void *ptr, char *str, bool on)
{
	(void)str;
	(void)on;
	if (ptr)
		free(ptr);
}
