/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarbant <gbarbant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:16:00 by gbarbant          #+#    #+#             */
/*   Updated: 2022/11/04 11:50:54 by gbarbant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_args(int argc, char **argv)
{
	if (argc > 2)
		return (printf("Error: too many arguments!\n"));
	if (argc < 2)
		return (printf("Error: too few arguments!\n"));
	if (!(argc == 2 && ft_strnstr(argv[1], ".cub", ft_strlen(argv[1]))
			&& ft_strlen(argv[1]) > 4))
		return (printf("Error: second argument is not a map!\n"));
	return (0);
}
