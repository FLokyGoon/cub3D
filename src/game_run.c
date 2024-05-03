/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbardeau <fbardeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:55:06 by fbardeau          #+#    #+#             */
/*   Updated: 2023/10/16 10:02:00 by fbardeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" 

/*
tex_pos : current pos of texture
step : how much increase the texture position for every pixel
*/

int	run(t_game *game)
{
	int		x;
	int		y;
	double	tex_pos;
	double	wallx;

	x = 0;
	while (x < 800)
	{
		game->ray.ray_num = x;
		init_ray_casting(game);
		first_case(game);
		send_one_ray(game);
		calculate_wall_height(game);
		if (game->ray.side == 0)
			wallx = game->player_y + game->ray.raydiry * game->correct_wall_dst;
		else
			wallx = game->player_x + game->ray.raydirx * game->correct_wall_dst;
		wallx -= floor(wallx);
		y = 0;
		y = run_ceiling_floor(game, x, y, wallx);
		x++;
	}
	move_player(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->img, 0, 0);
	return (0);
}

int	run_wall(t_game *game, int x, int y, double wallx)
{
	game->step = 1.0 * game->current_texture->hei / \
	(game->y_end - game->y_start);
	if (game->y_start < 0)
		game->y_start = -game->y_start;
	game->tex_pos = (game->y_start - WIN_HEIGHT / 2 + \
			(game->y_end - game->y_start) / 2) * game->step;
	if (game->y_end >= WIN_HEIGHT)
		game->y_end = WIN_HEIGHT - 1;
	game->tex_x = (int)(wallx * (double)game->current_texture->wid);
	if (game->ray.side == 0 && game->ray.raydirx > 0)
		game->tex_x = game->current_texture->wid - game->tex_x - 1;
	if (game->ray.side == 1 && game->ray.raydiry < 0)
		game->tex_x = game->current_texture->wid - game->tex_x - 1;
	while (y < game->y_end)
	{
		game->tex_y = (int)game->tex_pos & (game->current_texture->hei - 1);
		game->tex_pos += game->step;
		game->color = get_texture_color(game->current_texture, game->tex_x, \
		game->tex_y);
		put_pixel_to_img(game->img, WIN_WIDTH - x, y, game->color);
		y++;
	}
	return (y);
}

int	run_ceiling_floor(t_game *game, int x, int y, double wallx)
{
	while (y < game->y_start)
	{
		put_pixel_to_img(game->img, WIN_WIDTH - x, y, \
		game->ceiling_final);
		y++;
	}
	y = run_wall(game, x, y, wallx);
	while (y < WIN_HEIGHT)
	{
		put_pixel_to_img(game->img, WIN_WIDTH - x, y, game -> floor_final);
		y++;
	}
	return (y);
}
