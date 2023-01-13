/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <gcrocett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:35:42 by gcrocett          #+#    #+#             */
/*   Updated: 2022/08/02 17:25:03 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_utils.h"
#include "../includes/textures.h"

int	cmp_char(char c1, char c2)
{
	if ((unsigned char)c1 != (unsigned char)c2)
		return ((unsigned char)c1 - (unsigned char)c2);
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (cmp_char(s1[i], s2[i]))
			return (s1[i] - s2[i]);
		i++;
	}
	if (i < n)
		return (cmp_char(s1[i], s2[i]));
	return (0);
}

int	to_rgb_helper(char c)
{
	if (c >= '0' && c <= '9')
		return (c - 48);
	else
		return (c - 55);
}

t_color_trgb	to_rgb(char *hex_color)
{
	t_color_trgb	color;
	char			*hex_color_copy;

	hex_color_copy = hex_color;
	color.r = 16 * to_rgb_helper(*hex_color);
	hex_color++;
	color.r += 1 * to_rgb_helper(*hex_color);
	hex_color++;
	color.g = 16 * to_rgb_helper(*hex_color);
	hex_color++;
	color.g += 1 * to_rgb_helper(*hex_color);
	hex_color++;
	color.b = 16 * to_rgb_helper(*hex_color);
	hex_color++;
	color.b += 1 * to_rgb_helper(*hex_color);
	my_free(hex_color_copy, "to_rgb", 1);
	return (color);
}

char	*find_path(int path, t_alls *sts)
{
	if (path == 0)
		return (sts->paths.n_path);
	if (path == 1)
		return (sts->paths.s_path);
	if (path == 2)
		return (sts->paths.w_path);
	if (path == 3)
		return (sts->paths.e_path);
	return (0);
}
