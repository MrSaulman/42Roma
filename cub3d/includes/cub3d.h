/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarbant <gbarbant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:18:28 by gbarbant          #+#    #+#             */
/*   Updated: 2022/11/07 14:16:03 by gbarbant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

typedef struct s_window
{
	void		*mlx;
	void		*win;
}				t_window;

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct s_path
{
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	t_color		floor;
	t_color		ceiling;
}				t_path;

typedef struct s_game
{
	t_window	window;
	t_path		paths;
}				t_game;

void			check_args(int argc, char **argv, t_game *game);
int				my_exit(int err, char *msg, t_game *game);
void			init_paths(t_game *game);
void			parse_map(t_game *game, char *path);
int				for_each_line(char *line, t_game *game, int fd);

#endif
