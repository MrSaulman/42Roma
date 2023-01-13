/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <gcrocett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:46:46 by gcrocett          #+#    #+#             */
/*   Updated: 2022/08/26 17:38:12 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_utils.h"

int	render_next_frame(t_alls *sts);

int	my_exit(int err, char *msg, t_alls *sts)
{
	printf("error:\n%s\n", msg);
	ft_my_free(sts);
	exit(err);
}

int	init_path(t_alls *sts, int argc, char **argv)
{	
	int	map_path_len;

	if (argc != 2)
		my_exit(0, "invalid number of arguments", sts);
	map_path_len = ft_strlen(argv[1]);
	sts->paths.map_path = argv[1];
	sts->paths.map_path[map_path_len] = '\0';
	start_parsing(sts);
	if (map_check(sts) != 1)
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_alls		*sts;

	sts = (t_alls *)malloc(sizeof(t_alls));
	if (sts == NULL)
		return (0);
	if (!init_path(sts, argc, argv))
		return (0);
	save_files(sts);
	create_textures(sts);
	sts->wndw.mlx_image = mlx_init();
	sts->image_data = create_image(sts->resolution.x,
			sts->resolution.y, sts->wndw.mlx_image);
	sts->wndw.mlx_windows = mlx_new_window(sts->wndw.mlx_image,
			sts->resolution.x, sts->resolution.y, "TEST");
	initial_posrot(sts);
	mlx_loop_hook(sts->wndw.mlx_image, render_next_frame, sts);
	mlx_hook(sts->wndw.mlx_windows, 2, 1L << 0, my_keys, sts);
	mlx_hook(sts->wndw.mlx_windows, 17, 0L, my_destroy, sts);
	mlx_loop(sts->wndw.mlx_image);
	return (0);
}
