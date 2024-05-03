/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmin <vkuzmin@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:46:35 by fbardeau          #+#    #+#             */
/*   Updated: 2023/10/13 00:58:36 by vkuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	game.key = malloc(sizeof(char) * 5);
	if (!game.key)
		exit (0);
	if (argc != 2)
		ft_exit_fail ('r');
	ft_get_data_map(argv, &game);
	ft_check_map(&game);
	ft_check_name_fd(argv);
	init_game(&game);
	ft_init(&game, argv);
	return (0);
}
