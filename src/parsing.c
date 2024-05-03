/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbardeau <fbardeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:04:44 by fbardeau          #+#    #+#             */
/*   Updated: 2023/10/18 10:20:02 by fbardeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_element(t_game *game, int i, int j)
{
	if (ft_cmp(game->copy_map[i][j], CHAR_SEP) == 0)
		ft_exit_fail('e');
	if (i == 0 && game->copy_map[i][j] == '0')
		ft_exit_fail('b');
	if (i == game->height - 1 && game->copy_map[i][j] == '0')
		ft_exit_fail('b');
	if (j == 0 && game->state == sol)
		ft_exit_fail('b');
	if (j == 0 && game->state == espace && game->copy_map[i][j + 1] == '0')
		ft_exit_fail('b');
	if (game->state == sol && (game->copy_map[i][j + 1] == ' ' || \
		game->copy_map[i][j + 1] == '\n' || game->copy_map[i][j + 1] == '\0'))
		ft_exit_fail('b');
	if (game->state == espace && game->copy_map[i][j + 1] == '0')
		ft_exit_fail('b');
	if (game->copy_map[i][j] == '0')
	{
		if (game->copy_map[i + 1][j] == ' ' ||
			game->copy_map[i + 1][j] == '\n'
			|| game->copy_map[i + 1][j] == '\0')
			ft_exit_fail('b');
	}
}

void	ft_state(t_game *game, int i, int j)
{
	if (game->copy_map[i][j] == ' ')
		game->state = espace;
	if (game->copy_map[i][j] == '1')
		game->state = mur;
	if (game->copy_map[i][j] == '0')
		game->state = sol;
}

void	ft_check_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (game->copy_map[i][j] != '\n' && game->copy_map[i][j] != '\0')
		{
			(ft_void(), ft_state(game, i, j), ft_check_element(game, i, j));
			if (game->state == espace && (game->copy_map[i][j + 1] == ' ' || \
			game->copy_map[i][j + 1] == '1'))
				j++;
			else if (game->state == mur && (game->copy_map[i][j + 1] == ' ' || \
			game->copy_map[i][j + 1] == '1' || game->copy_map[i][j + 1] == \
				'0'))
				j++;
			else if (game->state == sol && (game->copy_map[i][j + 1] == '1' || \
			game->copy_map[i][j + 1] == '0'))
				j++;
			else
				j++;
		}
		i++;
	}
}

void	count_file_lines(char *fd_name, t_game *game)
{
	int		lines_count;
	int		fd;
	char	*line;

	lines_count = 0;
	fd = open(fd_name, O_RDONLY);
	if (fd < 0)
		ft_exit_fail('f');
	line = get_next_line(fd);
	while (line != NULL)
	{
		lines_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	game->file_lines_count = lines_count;
}

void	get_file_data(char *fd_name, t_game *game)
{
	int	i;
	int	fd;

	i = 0;
	game->file_copy = malloc(sizeof(char *) * game->file_lines_count);
	fd = open(fd_name, O_RDONLY);
	if (fd < 0)
		ft_exit_fail('f');
	while (i < game->file_lines_count)
	{
		game->file_copy[i] = get_next_line(fd);
		i++;
	}
}
