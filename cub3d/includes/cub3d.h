/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarbant <gbarbant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:18:28 by gbarbant          #+#    #+#             */
/*   Updated: 2022/11/03 17:14:03 by gbarbant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <mlx.h>
#include <math.h>
#include <fcntl.h>
#include "libft/inc/libft.h"
#include "libft/inc/get_next_line_bonus.h"

typedef struct s_window
{
	void *mlx;
	void *win;
}	t_window;

typedef struct s_game
{
	t_window window;

}	t_game;

int	check_args(int argc, char **argv);


#endif
