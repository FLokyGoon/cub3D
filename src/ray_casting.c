/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbardeau <fbardeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:06:04 by fbardeau          #+#    #+#             */
/*   Updated: 2023/10/16 09:57:10 by fbardeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
ray.camerax : give the relativ position of the ray in space between -1 to 1;
game->ray.raydirx direction of where the ray is send on the x axe;
delat x = cos ( of the angle) = adjacent side / hypotenus;
sidedistx: fist distance between the player and the firt vertical colon cross 
on x;
*/

void	init_ray_casting(t_game *game)
{
	game->ray.camerax = (2 * game->ray.ray_num / (double)WIN_WIDTH) - 1;
	game->ray.raydirx = game->angle_dir_x + game->ray.planex * \
	game->ray.camerax;
	game->ray.raydiry = game->angle_dir_y + game->ray.planey * \
	game->ray.camerax;
	game->ray.mapx = (int)game->player_x;
	game->ray.mapy = (int)game->player_y;
	if (game->ray.raydirx != 0)
		game->ray.delta_x = fabs(1 / game->ray.raydirx);
	else
		game->ray.delta_x = INFINITY;
	if (game->ray.raydiry != 0)
		game->ray.delta_y = fabs(1 / game->ray.raydiry);
	else
		game->ray.delta_y = INFINITY;
}

void	first_case(t_game *game)
{
	if (game->ray.raydirx < 0)
	{
		game->ray.stepx = -1;
		game->ray.sidedistx = (game->player_x - game->ray.mapx) * \
		game->ray.delta_x;
	}
	else
	{
		game->ray.stepx = 1;
		game->ray.sidedistx = (game->ray.mapx + 1.0 - game->player_x) * \
		game->ray.delta_x;
	}
	if (game->ray.raydiry < 0)
	{
		game->ray.stepy = -1;
		game->ray.sidedisty = (game->player_y - game->ray.mapy) * \
		game->ray.delta_y;
	}
	else
	{
		game->ray.stepy = 1;
		game->ray.sidedisty = (game->ray.mapy + 1.0 - game->player_y) * \
		game->ray.delta_y;
	}
}

void	send_one_ray_follow(t_game *game)
{
	if (game->ray.side == 0)
	{
		if (game->ray.raydirx > 0)
			game->current_texture = game->wall_texture_w;
		else
			game->current_texture = game->wall_texture_e;
	}
	else
	{
		if (game->ray.raydiry > 0)
			game->current_texture = game->wall_texture_n;
		else
			game->current_texture = game->wall_texture_s;
	}
}

void	send_one_ray(t_game *game)
{
	while (1)
	{
		if (game->ray.sidedistx < game->ray.sidedisty)
		{
			game->ray.sidedistx += game->ray.delta_x;
			game->ray.mapx += game->ray.stepx;
			game->ray.side = 0;
		}
		else
		{
			game->ray.sidedisty += game->ray.delta_y;
			game->ray.mapy += game->ray.stepy;
			game->ray.side = 1;
		}
		if (game->copy_map[game->ray.mapy][game->ray.mapx] == '1')
		{
			send_one_ray_follow(game);
			break ;
		}
	}
}

void	calculate_wall_height(t_game *game)
{
	double	correct_wall_dst;
	int		line_height;

	if (game->ray.side == 0)
	{
		correct_wall_dst = (game->ray.mapx - game->player_x + \
		(1 - game->ray.stepx) / 2) / game->ray.raydirx;
	}
	else
	{
		correct_wall_dst = (game->ray.mapy - game->player_y + \
		(1 - game->ray.stepy) / 2) / game->ray.raydiry;
	}
	line_height = (int)(WIN_HEIGHT / correct_wall_dst);
	game->y_start = -line_height / 2 + WIN_HEIGHT / 2;
	game->y_end = line_height / 2 + WIN_HEIGHT / 2;
	game->correct_wall_dst = correct_wall_dst;
}
