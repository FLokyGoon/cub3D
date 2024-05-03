/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbardeau <fbardeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:08:06 by vkuzmin           #+#    #+#             */
/*   Updated: 2023/10/11 10:17:51 by fbardeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(t_game *game)
{
	double	move_speed;
	double	new_x;
	double	new_y;

	move_speed = 0.025;
	new_x = game->player_x;
	new_y = game->player_y;
	if (game->key[0] == '1')
	{
		new_y = game->player_y + game->angle_dir_y * move_speed;
		new_x = game->player_x + game->angle_dir_x * move_speed;
		check_collision(game, new_x, new_y);
	}
	if (game->key[3] == '1')
	{
		new_y = game->player_y - game->angle_dir_x * move_speed;
		new_x = game->player_x + game->angle_dir_y * move_speed;
		check_collision(game, new_x, new_y);
	}
	move_player_follow(game, move_speed);
}

void	move_player_follow(t_game *game, double move_speed)
{
	double	new_x;
	double	new_y;

	new_x = game->player_x;
	new_y = game->player_y;
	if (game->key[2] == '1')
	{
		new_y = game->player_y - game->angle_dir_y * move_speed;
		new_x = game->player_x - game->angle_dir_x * move_speed;
		check_collision(game, new_x, new_y);
	}
	if (game->key[1] == '1')
	{
		new_y = game->player_y + game->angle_dir_x * move_speed;
		new_x = game->player_x - game->angle_dir_y * move_speed;
		check_collision(game, new_x, new_y);
	}
	rotate_camera(game);
}
