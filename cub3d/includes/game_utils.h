/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <gcrocett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:53:34 by gcrocett          #+#    #+#             */
/*   Updated: 2022/08/26 17:36:29 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_UTILS_H
# define GAME_UTILS_H

# include "./get_next_line.h"
# include "./parse.h"
# include "../includes/image_windows_utils.h"
# include "./structs.h"
# include "./textures.h"
# include "./atoi.h"
# define MMAP_W 11
# define MMAP_MARGIN 20

void	initial_posrot(t_alls *sts);
int		my_destroy(t_alls *sts);
int		my_keys(int keycode, t_alls *sts);
void	on_right(t_alls *sts);
void	on_left(t_alls *sts);
int		is_spawner(char c);
void	draw_minimap(t_alls *sts);
void	ft_my_free(t_alls *sts);
void	my_free(void *ptr, char *str, bool on);
void	conta_rc(int *cc, int *rr, char *fil, t_alls *sts);
void	debug_print_files(t_alls *sts);
void	fill_files(t_alls *sts);
void	save_files2(t_alls *sts);
void	save_files(t_alls *sts);
int		my_exit(int err, char *msg, t_alls *sts);

#endif
