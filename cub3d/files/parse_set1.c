/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_set1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <gcrocett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 13:13:57 by gcrocett          #+#    #+#             */
/*   Updated: 2022/08/26 16:39:16 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_utils.h" 

void	set_res(t_alls *sts)
{
	sts->resolution.x = RESX;
	sts->resolution.y = RESY;
}

int	parse_no(char *line, t_alls *sts)
{
	int	len;
	int	count;

	line++;
	line++;
	count = 0;
	line = skip_space(line);
	if (sts->paths.n_path != NULL)
		my_exit(0, "double n_path", sts);
	len = count_until_next_space(line);
	sts->paths.n_path = (char *)malloc(sizeof(char) * (len +1));
	if (sts->paths.n_path == NULL)
		my_exit(0, "malloc error  on n_path", sts);
	while (*line != ' ' && *line != '\0')
	{
		sts->paths.n_path[count] = *line;
		count ++;
		line++;
	}
	sts->paths.n_path[count] = '\0';
	return (1);
}

int	parse_so(char *line, t_alls *sts)
{
	int	len;
	int	count;

	line++;
	line++;
	count = 0;
	line = skip_space(line);
	if (sts->paths.s_path != NULL)
		my_exit(0, "double s_path", sts);
	len = count_until_next_space(line);
	sts->paths.s_path = (char *)malloc(sizeof(char) * (len +1));
	if (sts->paths.s_path == NULL)
		my_exit(0, "malloc error  on s_path", sts);
	while (*line != ' ' && *line != '\0')
	{
		sts->paths.s_path[count] = *line;
		count ++;
		line++;
	}
	sts->paths.s_path[count] = '\0';
	return (1);
}

int	parse_we(char *line, t_alls *sts)
{
	int	len;
	int	count;

	line++;
	line++;
	count = 0;
	line = skip_space(line);
	if (sts->paths.w_path != NULL)
		my_exit(0, "double w_path", sts);
	len = count_until_next_space(line);
	sts->paths.w_path = (char *)malloc(sizeof(char) * (len +1));
	if (sts->paths.w_path == NULL)
		my_exit(0, "malloc error  on w_path", sts);
	while (*line != ' ' && *line != '\0')
	{
		sts->paths.w_path[count] = *line;
		count ++;
		line++;
	}
	sts->paths.w_path[count] = '\0';
	return (1);
}

int	parse_ea(char *line, t_alls *sts)
{
	int	len;
	int	count;

	line++;
	line++;
	count = 0;
	line = skip_space(line);
	if (sts->paths.e_path != NULL)
		my_exit(0, "double e_path", sts);
	len = count_until_next_space(line);
	sts->paths.e_path = (char *)malloc(sizeof(char) * (len +1));
	if (sts->paths.e_path == NULL)
		my_exit(0, "malloc error  on e_path", sts);
	while (*line != ' ' && *line != '\0')
	{
		sts->paths.e_path[count] = *line;
		count ++;
		line++;
	}
	sts->paths.e_path[count] = '\0';
	return (1);
}
