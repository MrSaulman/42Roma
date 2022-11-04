/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarbant <gbarbant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 19:25:36 by asalvemi          #+#    #+#             */
/*   Updated: 2022/11/04 11:54:59 by gbarbant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_clean_line(char *save, char **line, int ret)
{
	unsigned int	i;
	char			*tmp;

	i = 0;
	while (save[i])
	{
		if (save[i] == '\n')
			break ;
		i++;
	}
	if (i < ft_strlen(save))
	{
		*line = ft_substr(save, 0, i);
		tmp = ft_substr(save, i + 1, ft_strlen(save));
		free(save);
		save = ft_strdup(tmp);
		free(tmp);
	}
	else if (ret == 0)
	{
		*line = save;
		save = NULL;
	}
	return (save);
}

char	*ft_save(char *buffer, char *save)
{
	char	*tmp;

	if (save)
	{
		tmp = ft_strjoin(save, buffer);
		free(save);
		save = ft_strdup(tmp);
		free(tmp);
	}
	else
		save = ft_strdup(buffer);
	return (save);
}

int	get_next_line(int fd, char **line)
{
	static char	*save[4096];
	char		buffer[BUFFER_SIZE + 1];
	int			ret;

	ret = read(fd, buffer, BUFFER_SIZE);
	while (ret)
	{
		if (ret == -1)
			return (-1);
		buffer[ret] = '\0';
		save[fd] = ft_save(buffer, save[fd]);
		if (ft_strchr(buffer, '\n'))
			break ;
		ret = read(fd, buffer, BUFFER_SIZE);
	}
	if (ret <= 0 && !save[fd])
	{
		*line = ft_strdup("");
		return (ret);
	}
	save[fd] = ft_clean_line(save[fd], line, ret);
	if (ret <= 0 && !save[fd])
		return (ret);
	return (1);
}
