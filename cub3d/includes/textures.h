/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <gcrocett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 13:16:18 by gcrocett          #+#    #+#             */
/*   Updated: 2022/07/14 17:10:16 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

# include "./structs.h"

t_color_trgb	to_rgb(char *hex_color);
char			*find_path(int path, t_alls *sts);
int				to_rgb_helper(char c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				cmp_char(char c1, char c2);
void			create_textures(t_alls *sts);
char			*find_hex(int file, int line_num, int col, t_alls *sts);
char			*c_to_hex(int file, t_alls *sts, char c);
char			*format_line(char *line);

#endif
