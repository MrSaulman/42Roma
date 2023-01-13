/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_set2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <gcrocett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 13:14:25 by gcrocett          #+#    #+#             */
/*   Updated: 2022/08/26 16:48:45 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_utils.h"

int	parse_floor(char *line, t_alls *sts)
{
	int	err;

	line++;
	line = skip_space(line);
	if (sts->floor_color.r != -1 || sts->floor_color.g != -1
		|| sts->floor_color.b != -1)
		my_exit(0, "double floor color", sts);
	err = copy_nbr(&sts->floor_color.r, line);
	if (err == 0)
		my_exit(0, "invalid floor red color", sts);
	line = skip_until_next_char(line, ',');
	line = skip_v(line);
	err = copy_nbr(&sts->floor_color.g, line);
	if (err == 0)
		my_exit(0, "invalid floor green color", sts);
	line = skip_until_next_char(line, ',');
	line = skip_v(line);
	err = copy_nbr(&sts->floor_color.b, line);
	if (err == 0)
		my_exit(0, "invalid floor blue color", sts);
	return (1);
}

int	parse_ceiling(char *line, t_alls *sts)
{
	int	err;

	line++;
	line = skip_space(line);
	if (sts->ceiling_color.r != -1 || sts->ceiling_color.g != -1
		|| sts->ceiling_color.b != -1)
		my_exit(0, "double ceiling color", sts);
	err = copy_nbr(&sts->ceiling_color.r, line);
	if (err == 0)
		my_exit(0, "invalid ceiling red color", sts);
	line = skip_until_next_char(line, ',');
	line = skip_v(line);
	err = copy_nbr(&sts->ceiling_color.g, line);
	if (err == 0)
		my_exit(0, "invalid ceiling green color", sts);
	line = skip_until_next_char(line, ',');
	line = skip_v(line);
	err = copy_nbr(&sts->ceiling_color.b, line);
	if (err == 0)
		my_exit(0, "invalid ceiling blue color", sts);
	return (1);
}

int	start_map_parse(char *line, t_alls *sts, int fd)
{
	int	map_line;
	int	line_len;
	int	i;

	i = 0;
	map_line = count_map_line(sts);
	sts->map = (char **)malloc(sizeof(char *) * (map_line + 1));
	if (sts->map == NULL)
		my_exit(0, "malloc error on map_parse", sts);
	while (map_line > 0)
	{
		line_len = ft_strlen(line);
		sts->map[i] = (char *)malloc(sizeof(char) * line_len);
		if (sts->map[i] == NULL)
			my_exit(0, "malloc error on map_parse", sts);
		sts->map[i] = line;
		get_next_line(fd, &line);
		map_line--;
		i++;
	}
	sts->map[i] = NULL;
	return (4242);
}
