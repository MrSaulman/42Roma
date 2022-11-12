/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarbant <gbarbant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:23:02 by gbarbant          #+#    #+#             */
/*   Updated: 2022/11/12 14:26:48 by gbarbant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	spaceskip(char *line, int i)
{
	int	count;

	count = i;
	while (line[count] == ' ')
		count++;
	return (count - i);
}

int	ft_pathlen(char *line, int i)
{
	int	ret;

	ret = 0;
	while (line[i] != ' ' || line[i] != '\n' || line[i] != '\0')
	{
		ret++;
		i++;
	}
	return (ret);
}

int	check_finished_line(char *line, int i)
{
	while (line[i] != '\n')
	{
		if (line[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}
