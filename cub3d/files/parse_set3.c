/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_set3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <gcrocett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 13:14:25 by gcrocett          #+#    #+#             */
/*   Updated: 2022/08/26 18:20:36 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_utils.h"

static void	alloca_mappa(t_alls *sts, int w, int h)
{
	int	i;
	int	j;

	sts->map_checker = (char **)malloc(sizeof(char *) * (h + 1));
	sts->map_checker[h] = NULL;
	i = 0;
	while (i < h)
	{
		sts->map_checker[i] = (char *)malloc(sizeof(char) * (w + 1));
		j = -1;
		while (++j < w)
			sts->map_checker[i][j] = ' ';
		sts->map_checker[i][j] = '\0';
		i++;
	}
}

static void	riempi_map_checker(t_alls *sts)
{
	int	x;
	int	y;

	y = 0;
	while (sts->map[y])
	{
		x = -1;
		while (sts->map[y][++x])
			sts->map_checker[y][x] = sts->map[y][x];
		y++;
	}
}

void	rettangolizza(t_alls *sts)
{
	int	max_w;
	int	max_h;
	int	x;
	int	y;

	y = -1;
	max_h = 0;
	max_w = 0;
	while (sts->map[++y])
	{
		x = -1;
		while (sts->map[y][++x])
		{
			if (x > max_w)
				max_w = x;
		}
		max_h++;
	}
	alloca_mappa(sts, max_w, max_h);
	riempi_map_checker(sts);
}

int	fix_open(t_alls *sts, char *fil)
{
	int	fd;

	fd = open(fil, O_RDONLY);
	if (fd == -1)
		my_exit(0, "invalid texture path", sts);
	return (fd);
}
