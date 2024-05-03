/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbardeau <fbardeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:17:26 by fbardeau          #+#    #+#             */
/*   Updated: 2023/10/18 10:18:08 by fbardeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_paths(t_game *game)
{
	int	fd1;
	int	fd2;
	int	fd3;
	int	fd4;

	fd1 = open(game->east_texture_path, O_RDONLY);
	if (fd1 < 0)
		ft_exit_fail('f');
	fd2 = open(game->north_texture_path, O_RDONLY);
	if (fd2 < 0)
		ft_exit_fail('f');
	fd3 = open(game->west_texture_path, O_RDONLY);
	if (fd3 < 0)
		ft_exit_fail('f');
	fd4 = open(game->south_texture_path, O_RDONLY);
	if (fd4 < 0)
		ft_exit_fail('f');
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
}

void	check_textures_res(t_game *game)
{
	remove_trailing_spaces(game->north_texture_path);
	remove_trailing_spaces(game->south_texture_path);
	remove_trailing_spaces(game->east_texture_path);
	remove_trailing_spaces(game->west_texture_path);
	check_end_line(game->north_texture_path);
	check_end_line(game->south_texture_path);
	check_end_line(game->east_texture_path);
	check_end_line(game->west_texture_path);
	remove_char(game->north_texture_path, '\n');
	remove_char(game->east_texture_path, '\n');
	remove_char(game->west_texture_path, '\n');
	remove_char(game->south_texture_path, '\n');
	check_paths(game);
}

void	check_column(char *line, int *index, int *cols)
{
	if (line[*index + 1] > '9' || line[*index + 1] < '0')
		ft_exit_fail('a');
}

void	check_cols(int *cols)
{
	if ((*cols) != 2)
		ft_exit_fail('a');
}

void	check_col_part2_helper(char *line, int *index, int *count, int *cols)
{
	while (line[*index] != '\0')
	{
		while (line[*index] >= '0' && line[*index] <= '9')
		{
			(*index)++;
			(*count)++;
			if (*count > 3)
				ft_exit_fail('a');
		}
		if (line[*index] == ',')
		{
			(*cols)++;
			check_column(line, index, cols);
			(*index)++;
			(*count) = 0;
		}
		if (line[*index] == '\n' && line[*index + 1] == '\0')
			break ;
		else if (line[*index] > '9' || line[*index] < '0')
			ft_exit_fail('a');
	}
	check_cols(cols);
}
