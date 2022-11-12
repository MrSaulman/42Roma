/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarbant <gbarbant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:28:31 by gbarbant          #+#    #+#             */
/*   Updated: 2022/11/12 14:27:02 by gbarbant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	parse_floor(char *line, t_game *game)
{
	int	i;

	i = 1;
	i += spaceskip(line, 1);
	if (game->paths.floor.r != -1 || game->paths.floor.g != -1
		|| game->paths.floor.b != -1)
		return (1);
	i += copy_nbr(&game->paths.floor.r, line, i);
	if (i == -1)
		return (1);
	if (line[i] == ',')
		i += copy_nbr(&game->paths.floor.g, line, i);
	if (i == -1)
		return (1);
	i++;
	if (line[i] == ',')
		i += copy_nbr(&game->paths.floor.b, line, i);
	if (i == -1)
		return (1);
	i++;
	if (check_finished_line(line, i))
		return (1);
	return (0);
}

int	parse_ceiling(char *line, t_game *game)
{
	int	i;

	i = 1;
	i += spaceskip(line, 1);
	if (game->paths.ceiling.r != -1 || game->paths.ceiling.g != -1
		|| game->paths.ceiling.b != -1)
		return (1);
	i += copy_nbr(&game->paths.ceiling.r, line, i);
	if (i == -1)
		return (1);
	if (line[i] == ',')
		i += copy_nbr(&game->paths.ceiling.g, line, i);
	if (i == -1)
		return (1);
	i++;
	if (line[i] == ',')
		i += copy_nbr(&game->paths.ceiling.b, line, i);
	if (i == -1)
		return (1);
	i++;
	if (check_finished_line(line, i))
		return (1);
	return (0);
}

int	copy_nbr(int *dest, char *line, int i)
{
	int		count;
	int		len;
	char	*ptr;

	if (line[i] == ',')
		i++;
	count = i;
	len = 0;
	while (line[count] > 47 && line[count++] < 58)
		len++;
	if (len > 3 || len == 0 || line[count] != ',' || line[count] != '\n'
		|| line[count] != ' ')
		return (-1);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (-1);
	count = 0;
	while (i < (i + len))
		ptr[count++] = line[i++];
	ptr[count] = '\0';
	*dest = ft_atoi(ptr);
	free(ptr);
	return (len);
}
