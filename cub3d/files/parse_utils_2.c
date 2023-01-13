/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <gcrocett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 13:12:04 by gcrocett          #+#    #+#             */
/*   Updated: 2022/08/25 17:58:20 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_utils.h"

int	copy_nbr(int *dest, char *line)
{
	int		len;
	int		count;
	char	*temp;
	char	*ptr;

	count = 0;
	len = count_until_next_space(line);
	temp = (char *)malloc(sizeof(char) * (len + 1));
	ptr = temp;
	while (count < len)
	{
		if (ft_isdigit(*line))
		{
			temp[count] = *line;
			line++;
			count++;
		}
		else
			return (0);
	}
	temp[count] = '\0';
	*dest = ft_atoi(temp);
	free(ptr);
	return (1);
}

char	*skip_until_bn(char *buf)
{
	while (*buf != '\n' && *buf != '\0')
		buf++;
	return (buf);
}

int	count_map_line(t_alls *sts)
{
	int		fd;
	char	*buf;
	char	*buf_copy;
	int		map_lines;

	map_lines = 0;
	buf = (char *)malloc(sizeof(char) * 4200);
	buf_copy = buf;
	fd = open(sts->paths.map_path, O_RDONLY);
	read(fd, buf, 4200);
	buf = skip_space(buf);
	while (ft_isdigit(*buf) != 1)
	{
		buf = skip_until_bn(buf);
		buf++;
		buf = skip_space(buf);
	}
	while (*buf != '\0')
	{
		buf = skip_until_bn(buf);
		map_lines++;
		buf++;
	}
	my_free(buf_copy, "count_map_line", 1);
	return (map_lines);
}

char	*skip_v(char *line)
{
	if (*line == ',')
	{
		while (*line == ',')
			line++;
	}
	return (line);
}

char	*skip_until_next_char(char *buf, char character)
{
	while (*buf != character)
		buf++;
	return (buf);
}
