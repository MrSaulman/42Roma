/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <gcrocett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:26:25 by gcrocett          #+#    #+#             */
/*   Updated: 2022/07/14 18:36:34 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_utils.h"

static int	return_err(int ret, int x)
{
	printf("error %d : ", x);
	if (x == 0)
		printf("'0' or spawner on the first line/column\n");
	else if (x == 1)
		printf("'0' or spawner on the last line/column\n");
	else if (x == 2)
		printf("'0' or spawner near ' '\n");
	else if (x == 3)
		printf("multiple spawners\n");
	else if (x == 4)
		printf("illegal character\n");
	else if (x == 5)
		printf("multiple spawners\n");
	else if (x == 6)
		printf("illegal char or adjacency error\n");
	else if (x == 7)
		printf("missing spawners\n");
	return (ret);
}

static int	is_legal(t_alls *sts, int x, int y)
{
	if (sts->map_checker[y][x] == '0' || is_spawner(sts->map_checker[y][x]))
	{
		if (x == 0 || y == 0)
			return (return_err(-1, 0));
		else if (!sts->map_checker[y][x + 1] || !sts->map_checker[y + 1])
			return (return_err(-1, 1));
		else if (sts->map_checker[y - 1][x] == ' ' ||
				sts->map_checker[y + 1][x] == ' ' ||
				sts->map_checker[y][x - 1] == ' ' ||
				sts->map_checker[y][x + 1] == ' ')
		{
			printf("x: %d y: %d c: %c\n", x, y, sts->map_checker[y][x]);
			return (return_err(-1, 2));
		}
	}
	return (1);
}

static int	set_spawn(t_alls *sts, int x, int y)
{
	if (sts->spawn_pos.x != 0 || sts->spawn_pos.y != 0)
		return (return_err(-1, 3));
	else
	{
		sts->spawn_pos.x = x;
		sts->spawn_pos.y = y;
		sts->spawn_dir = sts->map_checker[y][x];
		sts->map[y][x] = '0';
		return (1);
	}
}

static int	is_valid(char c)
{
	char	valid_c[7];
	int		l;

	l = 7;
	valid_c[0] = ' ';
	valid_c[1] = '1';
	valid_c[2] = '0';
	valid_c[3] = 'N';
	valid_c[4] = 'S';
	valid_c[5] = 'E';
	valid_c[6] = 'W';
	while (--l >= 0)
	{
		if (c == valid_c[l])
			return (1);
	}
	return (return_err(-1, 4));
}

int	map_check(t_alls *sts)
{
	int	x;
	int	y;

	y = 0;
	rettangolizza(sts);
	while (sts->map_checker[y])
	{
		x = 0;
		while (sts->map_checker[y][x])
		{
			if (is_spawner(sts->map_checker[y][x]))
				if (set_spawn(sts, x, y) != 1)
					return (return_err(-1, 5));
			if (is_legal(sts, x, y) != 1
				|| is_valid(sts->map_checker[y][x]) != 1)
				return (return_err(-1, 6));
			x++;
		}
		y++;
	}
	if (sts->spawn_pos.x == 0 || sts->spawn_pos.y == 0)
		return (return_err(-1, 7));
	return (1);
}
