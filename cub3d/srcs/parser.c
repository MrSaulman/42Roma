/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarbant <gbarbant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:16:00 by gbarbant          #+#    #+#             */
/*   Updated: 2022/11/07 15:40:20 by gbarbant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_args(int argc, char **argv, t_game *game)
{
	if (argc > 2)
		my_exit(1, "too many arguments!", game);
	if (argc < 2)
		my_exit(1, "too few arguments!", game);
	if (!(argc == 2 && ft_strnstr(argv[1], ".cub\0", ft_strlen(argv[1]))
			&& ft_strlen(argv[1]) > 4))
		my_exit(1, "not a valid map extension!", game);
}

void	init_paths(t_game *game)
{
	game->paths.ea_path = NULL;
	game->paths.we_path = NULL;
	game->paths.no_path = NULL;
	game->paths.so_path = NULL;
	game->paths.ceiling.r = -1;
	game->paths.ceiling.g = -1;
	game->paths.ceiling.b = -1;
	game->paths.floor.r = -1;
	game->paths.floor.g = -1;
	game->paths.floor.b = -1;
}

void	parse_map(t_game *game, char *path)
{
	int		fd;
	int		gnl;
	char	*line;

	gnl = 1;
	init_paths(game);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		my_exit(1, "invalid map path!", game);
	line = (char *)malloc(sizeof(char) * 100);
	if (line == NULL)
		my_exit(1, "allocation failed", game);
	while (gnl == 1)
	{
		gnl = get_next_line(fd, &line);
		if (for_each_line(line, game, fd))
		{
			free(line);
			my_exit(1, "Something happened in the map parsing :(", game);
		}
	}
	free(line);
	return (0);
}

int	for_each_line(char *line, t_game *game, int fd)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == 'N' && line[i + 1] == 'O')
		i = parse_no(line, game);
	else if (line[i] == 'S' && line[i + 1] == 'O')
		i = parse_so(line, game);
	else if (line[i] == 'W' && line[i + 1] == 'E')
		i = parse_we(line, game);
	else if (line[i] == 'E' && line[i + 1] == 'A')
		i = parse_ea(line, game);
	else if (line[i] == 'F')
		i = parse_floor(line, game);
	else if (line[i] == 'C')
		i = parse_ceiling(line, game);
	else if (line[i] == '1')
		i = start_map_parse(line, game, fd);
	else if (line[i] == '\0' || line[i] == '\n')
		return (0);
	else
		return (1);
	return (i);
}
