/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbardeau <fbardeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:51:26 by fbardeau          #+#    #+#             */
/*   Updated: 2023/10/11 09:34:46 by fbardeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* W, A, S, D, left arrow, right arrow*/

int	key_press(int key, t_game *game)
{
	if (key == 65307)
		exit(0);
	if (key == 119)
		game->key[0] = '1';
	if (key == 97)
		game->key[3] = '1';
	if (key == 115)
		game->key[2] = '1';
	if (key == 100)
		game->key[1] = '1';
	if (key == 65361)
		game->key[5] = '1';
	if (key == 65363)
		game->key[4] = '1';
	return (0);
}

int	key_release(int key, t_game *game)
{
	if (key == 119)
		game->key[0] = '0';
	if (key == 97)
		game->key[3] = '0';
	if (key == 115)
		game->key[2] = '0';
	if (key == 100)
		game->key[1] = '0';
	if (key == 65361)
		game->key[5] = '0';
	if (key == 65363)
		game->key[4] = '0';
	return (0);
}
