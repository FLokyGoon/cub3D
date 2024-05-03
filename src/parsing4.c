/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbardeau <fbardeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:18:29 by fbardeau          #+#    #+#             */
/*   Updated: 2023/10/18 10:19:01 by fbardeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_col_part2(char *line)
{
	int	index;
	int	count;
	int	cols;

	cols = 0;
	index = 0;
	count = 0;
	check_col_part2_helper(line, &index, &count, &cols);
}

void	check_col(t_game *game)
{
	check_col_part2(game->c_line);
	check_col_part2(game->f_line);
}

void	find_colors(t_game *game)
{
	int	i;
	int	f_counter;
	int	c_counter;

	f_counter = 0;
	c_counter = 0;
	i = 0;
	while (i < game->start_map_line)
	{
		if (game->file_copy[i][0] == 'F' && game->file_copy[i][1] == ' ')
		{
			game->f_line = ft_strdup(game->file_copy[i] + 2);
			f_counter++;
		}
		if (game->file_copy[i][0] == 'C' && game->file_copy[i][1] == ' ')
		{
			game->c_line = ft_strdup(game->file_copy[i] + 2);
			c_counter++;
		}
		i++;
	}
	check_counters(c_counter, f_counter);
}

void	make_colors(t_game *game)
{
	remove_char(game->f_line, '\n');
	remove_char(game->c_line, '\n');
	game->fl_color = ft_split(game->f_line, ',');
	game->ce_color = ft_split(game->c_line, ',');
}

void	create_colors(t_game *game)
{
	game -> floor_final = (game->floor_color[0] << 16)
		| (game->floor_color[1] << 8)
		| game->floor_color[2];
	game -> ceiling_final = (game->ceiling_color[0] << 16)
		| (game->ceiling_color[1] << 8)
		| game->ceiling_color[2];
}
