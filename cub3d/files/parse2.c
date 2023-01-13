/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <gcrocett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:08:48 by gcrocett          #+#    #+#             */
/*   Updated: 2022/08/26 18:19:58 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_utils.h"

void	conta_rc(int *cc, int *rr, char *fil, t_alls *sts)
{
	int		max;
	int		r;
	int		c;
	char	buf;
	int		fd;

	max = 0;
	c = 0;
	r = 0;
	fd = fix_open(sts, fil);
	while (read(fd, &buf, 1))
	{
		c++;
		if (buf == '\n')
		{
			r += 1;
			if (c > max)
				max = c;
			c = 0;
		}
	}
	close(fd);
	*rr = r;
	*cc = max;
}

void	debug_print_files(t_alls *sts)
{
	int	i;

	i = 0;
	printf("NORTH\n");
	while (i < sts->tex_file.nr)
		printf("%s\n", sts->tex_file.north[i++]);
	i = 0;
	printf("\nSOUTH\n");
	while (i < sts->tex_file.sr)
		printf("%s\n", sts->tex_file.south[i++]);
	i = 0;
	printf("\nWEST\n");
	while (i < sts->tex_file.wr)
		printf("%s\n", sts->tex_file.west[i++]);
	i = 0;
	printf("\nEAST\n");
	while (i < sts->tex_file.er)
		printf("%s\n", sts->tex_file.east[i++]);
}

void	copy_line(char *in, char *out)
{
	int	i;

	i = 0;
	while (in[i])
	{
		out[i] = in[i];
		i++;
	}
	out[i] = '\0';
}

static void	fill_files2(t_alls *sts, char *line)
{
	int		fd;
	int		i;

	i = 0;
	fd = open(find_path(2, sts), O_RDONLY);
	if (fd == -1)
		my_exit(0, "invalid w_path", sts);
	while (get_next_line(fd, &line) > 0)
		copy_line(line, sts->tex_file.west[i++]);
	close(fd);
	i = 0;
	fd = open(find_path(3, sts), O_RDONLY);
	if (fd == -1)
		my_exit(0, "invalid e_path", sts);
	while (get_next_line(fd, &line) > 0)
		copy_line(line, sts->tex_file.east[i++]);
	close(fd);
}

void	fill_files(t_alls *sts)
{
	int		fd;
	int		i;
	char	*line;
	char	*ptr;

	i = 0;
	line = (char *)malloc(sizeof(char) * 100);
	ptr = line;
	fd = open(find_path(0, sts), O_RDONLY);
	if (fd == -1)
		my_exit(0, "invalid n_path", sts);
	while (get_next_line(fd, &line) > 0)
		copy_line(line, sts->tex_file.north[i++]);
	close(fd);
	i = 0;
	fd = open(find_path(1, sts), O_RDONLY);
	if (fd == -1)
		my_exit(0, "invalid s_path", sts);
	while (get_next_line(fd, &line) > 0)
	{
		copy_line(line, sts->tex_file.south[i++]);
	}
	close(fd);
	fill_files2(sts, line);
	free(ptr);
}
