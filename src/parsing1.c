/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbardeau <fbardeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:00:17 by vkuzmin           #+#    #+#             */
/*   Updated: 2023/10/18 10:16:24 by fbardeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_map_start(t_game *game)
{
	int	i;

	i = 0;
	while (game->file_copy[i])
	{
		if (game->file_copy[i][0] == '1')
		{
			game->start_map_line = i;
			break ;
		}
		i++;
	}
}

void	find_flags(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->start_map_line)
	{
		if (!((game->file_copy[i][0] == 'N' && game->file_copy[i][1] == 'O'
			&& game->file_copy[i][2] == ' ') || (game->file_copy[i][0] == 'S'
			&& game->file_copy[i][1] == 'O' && game->file_copy[i][2] == ' ')
			|| (game->file_copy[i][0] == 'W' && game->file_copy[i][1] == 'E'
			&& game->file_copy[i][2] == ' ') || (game->file_copy[i][0] == 'E'
			&& game->file_copy[i][1] == 'A' && game->file_copy[i][2] == ' ')
			|| (game->file_copy[i][0] == 'F' && game->file_copy[i][1] == ' ')
			|| (game->file_copy[i][0] == 'C' && game->file_copy[i][1] == ' ')
			|| (game->file_copy[i][0] == '\n'
			&& game->file_copy[i][1] == '\0')))
			ft_exit_fail('a');
		i++;
	}
}

void	check_counters(int counter1, int counter2)
{
	if (counter1 > 1 || counter2 > 1)
		ft_exit_fail('a');
	if (counter1 == 0 || counter2 == 0)
		ft_exit_fail('a');
}

void	check_incs2(t_game *game)
{
	int	i;
	int	we_counter;
	int	so_counter;

	i = 0;
	we_counter = 0;
	so_counter = 0;
	while (i < game->start_map_line)
	{
		if (game->file_copy[i][0] == 'W' && game->file_copy[i][1] == 'E'
			&& game->file_copy[i][2] == ' ')
		{
			we_counter++;
		}
		if (game->file_copy[i][0] == 'S' && game->file_copy[i][1] == 'O'
			&& game->file_copy[i][2] == ' ')
		{
			so_counter++;
		}
		i++;
	}
	check_counters(so_counter, we_counter);
}

void	check_incs1(t_game *game)
{
	int	i;
	int	we_counter;
	int	so_counter;

	i = 0;
	we_counter = 0;
	so_counter = 0;
	while (i < game->start_map_line)
	{
		if (game->file_copy[i][0] == 'N' && game->file_copy[i][1] == 'O'
			&& game->file_copy[i][2] == ' ')
		{
			we_counter++;
		}
		if (game->file_copy[i][0] == 'E' && game->file_copy[i][1] == 'A'
			&& game->file_copy[i][2] == ' ')
		{
			so_counter++;
		}
		i++;
	}
	check_counters(so_counter, we_counter);
}
