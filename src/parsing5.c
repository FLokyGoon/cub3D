/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbardeau <fbardeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:19:22 by fbardeau          #+#    #+#             */
/*   Updated: 2023/10/18 10:19:55 by fbardeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_colors(t_game *game)
{
	int	j;

	j = 0;
	game->floor_color = malloc(sizeof(int) * 3);
	game->ceiling_color = malloc(sizeof(int) * 3);
	while (j < 3)
	{
		game->floor_color[j] = ft_atoi(game->fl_color[j]);
		j++;
	}
	j = 0;
	while (j < 3)
	{
		game->ceiling_color[j] = ft_atoi(game->ce_color[j]);
		j++;
	}
	create_colors(game);
}

void	check_pos(int i, int j, t_game *game)
{
	if (game->map[i][j + 1] != '0' && game->map[i][j + 1] != '1')
		ft_exit_fail('a');
	if (game->map[i][j - 1] != '0' && game->map[i][j - 1] != '1')
		ft_exit_fail('a');
	if (game->map[i + 1][j] != '0' && game->map[i + 1][j] != '1')
		ft_exit_fail('a');
	if (game->map[i - 1][j] != '0' && game->map[i - 1][j] != '1')
		ft_exit_fail('a');
}

void	check_n(t_game *game)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		while (game->map[i][j] != '\n' && game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'S' || game->map[i][j] == 'E'
				|| game->map[i][j] == 'W' || game->map[i][j] == 'N')
				check_pos(i, j, game);
			j++;
		}
		j = 0;
		i++;
	}
}

int	ft_get_data_map(char **argv, t_game *game)
{
	count_file_lines(argv[1], game);
	get_file_data(argv[1], game);
	find_map_start(game);
	find_flags(game);
	check_incs1(game);
	check_incs2(game);
	get_textures1(game);
	get_textures2(game);
	check_textures_res(game);
	find_colors(game);
	check_col(game);
	make_colors(game);
	fill_colors(game);
	game->height = ft_height(argv[1], game);
	game->width = ft_width(argv[1], game);
	game->map = ft_copy_map(argv[1], game->height, game->width, game);
	check_n(game);
	game->copy_map = ft_copy_map(argv[1], game->height, game->width, game);
	return (0);
}

void	ft_init_pos(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->copy_map[i][j] == 'N')
			{
				game->x_init = j;
				game->y_init = i;
			}
			j++;
		}
		i++;
	}
}
