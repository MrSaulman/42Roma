/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:35:42 by gcrocett          #+#    #+#             */
/*   Updated: 2022/07/30 17:24:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_utils.h"
#include "../includes/textures.h"

char	*format_line(char *line)
{
	char	*ret_line;
	int		j;

	j = 0;
	ret_line = (char *)malloc(sizeof(char) * 7);
	if (ret_line == NULL)
		return (0);
	while (line[j + 7] != ',')
	{
		ret_line[j] = line[j + 6];
		j++;
	}
	ret_line[6] = '\0';
	return (ret_line);
}

char	**ret_saved_xpm(int i, t_alls *sts)
{
	if (i == 0)
		return (sts->tex_file.north);
	if (i == 1)
		return (sts->tex_file.south);
	if (i == 2)
		return (sts->tex_file.west);
	if (i == 3)
		return (sts->tex_file.east);
	return (0);
}

char	*c_to_hex(int file, t_alls *sts, char c)
{
	int		i;
	char	**line;

	i = 4;
	line = ret_saved_xpm(file, sts);
	while (ft_strncmp(line[i], "/* pixels */", 11))
	{
		if (line[i][1] == c)
			return (format_line(line[i]));
		else
			i++;
	}
	return (0);
}

char	*find_hex(int file, int line_num, int col, t_alls *sts)
{
	int		i;
	char	**line;
	char	c;

	i = 0;
	line = ret_saved_xpm(file, sts);
	while (ft_strncmp(line[i], "/* pixels */", 11))
		i++;
	i++;
	while (line_num-- > 0)
		i++;
	c = line[i][col + 1];
	return (c_to_hex(file, sts, c));
}

void	create_textures(t_alls *sts)
{
	int		i;
	int		j;
	int		t;
	char	*ret_line;

	t = 0;
	while (t < 4)
	{
		i = 0;
		while (i < 32)
		{
			j = 0;
			while (j < 32)
			{
				ret_line = find_hex(t, i, j, sts);
				sts->tex.texture[t][i][j] = to_rgb(ret_line);
				j++;
			}
			i++;
		}
		t++;
	}
}
