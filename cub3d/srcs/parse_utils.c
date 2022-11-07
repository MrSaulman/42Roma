/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarbant <gbarbant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:23:02 by gbarbant          #+#    #+#             */
/*   Updated: 2022/11/07 15:36:05 by gbarbant         ###   ########.fr       */
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
		ret++;
	return (ret);
}
