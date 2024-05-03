/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmin <vkuzmin@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:51:32 by fbardeau          #+#    #+#             */
/*   Updated: 2023/10/13 16:53:54 by vkuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_direction(t_game *game)
{
	game->angle_dir_x = 0;
	game->angle_dir_y = 0;
	if (game->init_pos == 1)
	{
		game->angle_dir_y = -1;
		game->ray.planex = -0.66;
	}
	else if (game->init_pos == 2)
	{
		game->angle_dir_y = 1;
		game->ray.planex = 0.66;
	}
	else if (game->init_pos == 4)
	{
		game->angle_dir_x = 1;
		game->ray.planey = -0.66;
	}
	else if (game->init_pos == 3)
	{
		game->angle_dir_x = -1;
		game->ray.planey = 0.66;
	}
}

void	init_game(t_game *game)
{
	ft_init_pos(game);
	check_element(game);
	game->player_x = (double)game->x_init + 0.5;
	game->player_y = (double)game->y_init + 0.5;
	game->ray.planey = 0;
	game->player_angle = fmod(game->player_angle, 2 * M_PI);
	if (game->player_angle < 0)
		game->player_angle += 2 * M_PI;
	game->planx = 0.66 * sin(game->player_angle);
	game->plany = -0.66 * cos(game->player_angle);
	init_direction(game);
	game->key = calloc(7, sizeof(char));
	if (!game->key)
		exit (EXIT_FAILURE);
}

void	init_textures(t_game *game)
{
	game->wall_texture_n = malloc(sizeof(t_img));
	game->wall_texture_s = malloc(sizeof(t_img));
	game->wall_texture_e = malloc(sizeof(t_img));
	game->wall_texture_w = malloc(sizeof(t_img));
	ft_img(game, game->north_texture_path, game->wall_texture_n);
	ft_img(game, game->south_texture_path, game->wall_texture_s);
	ft_img(game, game->east_texture_path, game->wall_texture_e);
	ft_img(game, game->west_texture_path, game->wall_texture_w);
}

int	ft_init(t_game *game, char **argv)
{
	t_img	tmp;

	game->img = malloc(sizeof(t_img));
	if (!game->img)
		exit(EXIT_FAILURE);
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, 800, 600, "cub3D");
	init_textures(game);
	if (!game->wall_texture_n || !game->wall_texture_s || !game->wall_texture_e \
			|| !game->wall_texture_w)
		exit(EXIT_FAILURE);
	tmp.img = mlx_new_image(game->mlx_ptr, 800, 600);
	tmp.addr = mlx_get_data_addr(tmp.img, &tmp.bpp, &tmp.line_len, &tmp.endian);
	tmp.wid = 800;
	tmp.hei = 600;
	game->img = &tmp;
	mlx_loop_hook(game->mlx_ptr, run, game);
	mlx_hook(game->win_ptr, 33, 1L << 17, ft_exit, game);
	mlx_hook(game->win_ptr, 2, 1L << 0, key_press, game);
	mlx_hook(game->win_ptr, 3, 1L << 1, key_release, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}
