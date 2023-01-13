/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iwu2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <gcrocett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:52:29 by gcrocett          #+#    #+#             */
/*   Updated: 2022/07/14 14:20:41 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_utils.h"

void	verticalstripe(t_img_data *img, int x, int drawse, int color)
{
	int	drawstart;
	int	drawend;

	drawstart = drawse / 10000;
	drawend = drawse % 10000;
	while (drawstart <= drawend)
	{
		mlx_pixel_put_fast(img, x, drawstart, color);
		drawstart++;
	}
}

t_img_data	*create_image(int size_x, int size_y, void *mlx_image)
{
	t_img_data	*img;

	img = (t_img_data *)malloc(sizeof(t_img_data));
	if (!(img))
		return (0);
	mlx_image = mlx_init();
	img->image = mlx_new_image(mlx_image, size_x, size_y);
	img->address = mlx_get_data_addr(img->image, &img->bits_per_pixel,
			&img->line_lenght, &img->endian);
	return (img);
}

void	mlx_pixel_put_fast(t_img_data *img_data, int x, int y, int clr)
{
	char	*destination;

	destination = img_data->address
		+ (y * img_data->line_lenght + x * (img_data->bits_per_pixel / 8));
	*(unsigned int *)destination = clr;
}

int	make_color(int t, int r, int g, int b)
{
	if (t > 255)
		t = 255;
	else if (t < 0)
		t = 0;
	if (r > 255)
		r = 255;
	else if (r < 0)
		r = 0;
	if (g > 255)
		g = 255;
	else if (g < 0)
		g = 0;
	if (b > 255)
		b = 255;
	else if (b < 0)
		b = 0;
	return (t << 24 | r << 16 | g << 8 | b);
}
