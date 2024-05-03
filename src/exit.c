/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbardeau <fbardeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:52:37 by fbardeau          #+#    #+#             */
/*   Updated: 2023/09/20 16:24:54 by fbardeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_exit(t_game *game)
{
	(void)game;
	exit(EXIT_SUCCESS);
}

void	ft_exit_fail(char c)
{
	write (2, "Error\n", 6);
	if (c == 'p')
		printf("No way to win\n");
	else if (c == 'f')
		printf("Error fd name\n");
	else if (c == 'c')
		printf("square map\n");
	else if (c == 'b')
		printf("false map border\n");
	else if (c == 'e')
		printf("wrong element in the map\n");
	else if (c == 'E')
		printf("exit or player or collectible missing in map\n");
	else if (c == 'a')
		printf("parsing error\n");
	exit (EXIT_FAILURE);
}
