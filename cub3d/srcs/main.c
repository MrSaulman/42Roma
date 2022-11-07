/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarbant <gbarbant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:58:23 by gbarbant          #+#    #+#             */
/*   Updated: 2022/11/07 13:03:56 by gbarbant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	my_exit(int err, char *msg, t_game *game)
{
	printf("error:\n%s\n", msg);
	ft_my_free(game);
	exit(err);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (game == NULL)
		my_exit(1, "allocation failed", game);
	check_args(argc, argv, game);
	parse_map(game, argv[1]);
	free(game);
}
