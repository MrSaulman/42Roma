/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarbant <gbarbant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:21:06 by gbarbant          #+#    #+#             */
/*   Updated: 2022/11/07 15:36:00 by gbarbant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	parse_no(char *line, t_game *game)
{
	int	i;
	int	j;
	int	len;

	i = 2;
	j = 0;
	i += spacekip(line, 2);
	if (game->paths.no_path != NULL)
		return (1);
	len = ft_pathlen(line, i);
	game->paths.no_path = (char *)malloc(sizeof(char) * (len + 1));
	if (game->paths.no_path == NULL)
		return (1);
	while (j < len)
		game->paths.no_path[j++] = line[i++];
	game->paths.no_path[j] = '\0';
	return (0);
}

int	parse_so(char *line, t_game *game)
{
	int	i;
	int	j;
	int	len;

	i = 2;
	j = 0;
	i += spacekip(line, 2);
	if (game->paths.so_path != NULL)
		return (1);
	len = ft_pathlen(line, i);
	game->paths.so_path = (char *)malloc(sizeof(char) * (len + 1));
	if (game->paths.so_path == NULL)
		return (1);
	while (j < len)
		game->paths.so_path[j++] = line[i++];
	game->paths.so_path[j] = '\0';
	return (0);
}

int	parse_we(char *line, t_game *game)
{
	int	i;
	int	j;
	int	len;

	i = 2;
	j = 0;
	i += spacekip(line, 2);
	if (game->paths.we_path != NULL)
		return (1);
	len = ft_pathlen(line, i);
	game->paths.we_path = (char *)malloc(sizeof(char) * (len + 1));
	if (game->paths.we_path == NULL)
		return (1);
	while (j < len)
		game->paths.we_path[j++] = line[i++];
	game->paths.we_path[j] = '\0';
	return (0);
}

int	parse_ea(char *line, t_game *game)
{
	int	i;
	int	j;
	int	len;

	i = 2;
	j = 0;
	i += spacekip(line, 2);
	if (game->paths.ea_path != NULL)
		return (1);
	len = ft_pathlen(line, i);
	game->paths.ea_path = (char *)malloc(sizeof(char) * (len + 1));
	if (game->paths.ea_path == NULL)
		return (1);
	while (j < len)
		game->paths.ea_path[j++] = line[i++];
	game->paths.ea_path[j] = '\0';
	return (0);
}
