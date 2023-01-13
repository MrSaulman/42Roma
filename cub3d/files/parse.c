/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <gcrocett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:08:48 by gcrocett          #+#    #+#             */
/*   Updated: 2022/08/26 18:14:38 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_utils.h"

void	save_files2(t_alls *sts)
{
	int	c;
	int	r;
	int	i;

	conta_rc(&c, &r, find_path(2, sts), sts);
	sts->tex_file.west = (char **)malloc(sizeof(char *) * r);
	sts->tex_file.wr = r;
	sts->tex_file.wc = c;
	i = -1;
	while (++i < r)
		sts->tex_file.west[i] = (char *)malloc(sizeof(char) * c);
	conta_rc(&c, &r, find_path(3, sts), sts);
	sts->tex_file.east = (char **)malloc(sizeof(char *) * r);
	sts->tex_file.er = r;
	sts->tex_file.ec = c;
	i = -1;
	while (++i < r)
		sts->tex_file.east[i] = (char *)malloc(sizeof(char) * c);
	fill_files(sts);
}

void	save_files(t_alls *sts)
{
	int	c;
	int	r;
	int	i;

	conta_rc(&c, &r, find_path(0, sts), sts);
	sts->tex_file.north = (char **)malloc(sizeof(char *) * r);
	sts->tex_file.nr = r;
	sts->tex_file.nc = c;
	i = -1;
	while (++i < r)
		sts->tex_file.north[i] = (char *)malloc(sizeof(char) * c);
	conta_rc(&c, &r, find_path(1, sts), sts);
	sts->tex_file.south = (char **)malloc(sizeof(char *) * r);
	sts->tex_file.sr = r;
	sts->tex_file.sc = c;
	i = -1;
	while (++i < r)
		sts->tex_file.south[i] = (char *)malloc(sizeof(char) * c);
	save_files2(sts);
}

int	start_parsing(t_alls *sts)
{
	int		fd;
	char	*line;
	char	*ptr;
	int		gnl;

	gnl = 1;
	if (!check_ext(sts, "cub"))
		my_exit(0, "invalid map extention", sts);
	init_par(sts);
	fd = open(sts->paths.map_path, O_RDONLY);
	if (fd == -1)
		my_exit(0, "invalid map path", sts);
	line = (char *)malloc(sizeof(char) * 100);
	ptr = line;
	while (gnl == 1)
	{
		gnl = get_next_line(fd, &line);
		foreach_line(line, sts, fd);
	}
	set_res(sts);
	free(ptr);
	return (1);
}

int	foreach_line(char *line, t_alls *sts, int fd)
{
	if (check_next_char(line, '1') != 1)
		line = skip_space(line);
	if (line[0] == 'N' && line[1] == 'O')
		parse_no(line, sts);
	else if (line[0] == 'S' && line[1] == 'O')
		parse_so(line, sts);
	else if (line[0] == 'W' && line[1] == 'E')
		parse_we(line, sts);
	else if (line[0] == 'E' && line[1] == 'A')
		parse_ea(line, sts);
	else if (line[0] == 'F')
		parse_floor(line, sts);
	else if (line[0] == 'C')
		parse_ceiling(line, sts);
	else if (line[0] == ' ' || line[0] == '1')
		start_map_parse(line, sts, fd);
	else if (line[0] == '\0')
		return (1);
	return (0);
}

int	check_next_char(char *line, char num)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == num)
		return (1);
	return (0);
}
