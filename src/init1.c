/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbardeau <fbardeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:38:00 by fbardeau          #+#    #+#             */
/*   Updated: 2023/10/11 09:43:12 by fbardeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_element(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < game->height)
	{
		j = 0;
		while (game->copy_map[i][j] != '\n' && game->copy_map[i][j] != '\0')
		{
			if (game->copy_map[i][j] == 'N')
				(ft_void(), game->init_pos = 1,
					count++, game->x_init = j, game->y_init = i);
			if (game->copy_map[i][j] == 'E')
				(ft_void(), game->init_pos = 4,
					count++, game->x_init = j, game->y_init = i);
			count = check_element_follow(game, i, j, count);
			j++;
		}
		i++;
	}
	if (count != 1)
		ft_exit_fail('e');
}

int	check_element_follow(t_game *game, int i, int j, int count)
{
	if (game->copy_map[i][j] == 'S')
	{
		game->init_pos = 2;
		count++;
		game->x_init = j;
		game->y_init = i;
	}
	if (game->copy_map[i][j] == 'W')
	{
		game->init_pos = 3;
		count++;
		game->x_init = j;
		game->y_init = i;
	}
	return (count);
}
