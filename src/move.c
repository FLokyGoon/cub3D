/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbardeau <fbardeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:58:33 by fbardeau          #+#    #+#             */
/*   Updated: 2023/10/16 09:59:25 by fbardeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_collision(t_game *game, double new_x, double new_y)
{
	if (game->map[(int)(new_y + 0.2)][(int)(new_x + 0.2)] == '1' || \
		game->map[(int)(new_y - 0.2)][(int)(new_x - 0.2)] == '1' || \
		game->map[(int)(new_y + 0.2)][(int)(new_x - 0.2)] == '1' || \
		game->map[(int)(new_y - 0.2)][(int)(new_x + 0.2)] == '1')
		return (1);
	return (0);
}

void	rotate_camera(t_game *game)
{
	double	old_plane_x;
	double	rot_speed;
	double	old_dir_x;

	old_dir_x = 0.0;
	old_plane_x = 0.0;
	rot_speed = 0.015;
	if (game->key[5] == '1')
	{
		old_dir_x = game->angle_dir_x;
		game->angle_dir_x = game->angle_dir_x * cos(-rot_speed) - \
		game->angle_dir_y * sin(-rot_speed);
		game->angle_dir_y = old_dir_x * sin(-rot_speed) + game->angle_dir_y * \
		cos(-rot_speed);
		old_plane_x = game->ray.planex;
		game->ray.planex = game->ray.planex * cos(-rot_speed) - \
		game->ray.planey * sin(-rot_speed);
		game->ray.planey = old_plane_x * sin(-rot_speed) + game->ray.planey * \
		cos(-rot_speed);
	}
	rotate_camera_follow(game, old_dir_x, old_plane_x, rot_speed);
}

void	rotate_camera_follow(t_game *game, double old_dir_x, \
						double old_plane_x, double rot_speed)
{
	if (game->key[4] == '1')
	{
		old_dir_x = game->angle_dir_x;
		game->angle_dir_x = game->angle_dir_x * cos(rot_speed) - \
		game->angle_dir_y * sin(rot_speed);
		game->angle_dir_y = old_dir_x * sin(rot_speed) + game->angle_dir_y * \
		cos(rot_speed);
		old_plane_x = game->ray.planex;
		game->ray.planex = game->ray.planex * cos(rot_speed) - \
		game->ray.planey * sin(rot_speed);
		game->ray.planey = old_plane_x * sin(rot_speed) + game->ray.planey * \
		cos(rot_speed);
	}
}

void	check_collision(t_game *game, double new_x, double new_y)
{
	if (!is_collision(game, new_x, game->player_y))
		game->player_x = new_x;
	if (!is_collision(game, game->player_x, new_y))
		game->player_y = new_y;
}
