/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <gcrocett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:55:41 by gcrocett          #+#    #+#             */
/*   Updated: 2022/08/25 18:07:09 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_vec2int
{
	int	x;
	int	y;
}	t_vec2int;

typedef struct s_img_data
{
	void	*image;
	char	*address;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}	t_img_data;

typedef struct s_wndw
{
	void	*mlx_windows;
	void	*mlx_image;
}	t_wndw;

typedef struct s_color_trgb
{
	int	t;
	int	r;
	int	g;
	int	b;
}	t_color_trgb;

typedef struct s_tex
{
	t_color_trgb	texture[4][32][32];
}	t_tex;

typedef struct s_path
{
	char	*n_path;
	char	*s_path;
	char	*w_path;
	char	*e_path;
	char	*sprite_path;
	char	*map_path;
}	t_path;

typedef struct s_move
{
	float	posx;
	float	posy;
	float	dirx;
	float	diry;
	float	planex;
	float	planey;
}	t_move;

typedef struct s_raycast
{
	double	camerax;
	double	raydirx;
	double	raydiry;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		mapx;
	int		mapy;
	int		hit;
	int		side;
	int		stepx;
	int		stepy;
	double	wallx;
	double	wally;
	int		wall_dir;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		wall_color;
	int		floor_color;
	int		roof_color;
	double	step_draw;
	int		texy;
}	t_raycast;

typedef struct s_saved_tex
{
	char	**north;
	int		nr;
	int		nc;
	char	**south;
	int		sr;
	int		sc;
	char	**east;
	int		er;
	int		ec;
	char	**west;
	int		wr;
	int		wc;
}	t_saved_tex;

typedef struct s_alls
{
	t_img_data		*image_data;
	t_color_trgb	floor_color;
	t_color_trgb	ceiling_color;
	t_vec2int		resolution;
	t_path			paths;
	t_wndw			wndw;
	t_move			move;
	t_tex			tex;
	t_vec2int		spawn_pos;
	t_raycast		raycast;
	char			spawn_dir;
	t_saved_tex		tex_file;
	char			**map;
	char			**map_checker;
	int				iniziali;
}	t_alls;

#endif