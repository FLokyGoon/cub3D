/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmin <vkuzmin@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:08:08 by fbardeau          #+#    #+#             */
/*   Updated: 2023/10/13 00:52:29 by vkuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	open_file(char *fd_name)
{
	int	fd;

	fd = open(fd_name, O_RDONLY);
	if (fd < 0)
		ft_exit_fail('f');
	return (fd);
}

void	read_initial_lines(int fd, t_game *game)
{
	char	*map;
	int		i;

	i = 0;
	while (i < game->start_map_line)
	{
		map = get_next_line(fd);
		free(map);
		i++;
	}
}

int	read_remaining_lines(int fd)
{
	char	*map;
	int		i;

	i = 0;
	while (1)
	{
		map = get_next_line(fd);
		if (map == NULL)
		{
			free(map);
			break ;
		}
		free(map);
		i++;
	}
	return (i);
}

int	ft_height(char *fd_name, t_game *game)
{
	int	fd;
	int	count;

	fd = open_file(fd_name);
	read_initial_lines(fd, game);
	count = read_remaining_lines(fd);
	close(fd);
	return (count);
}

int	open_and_skip_initial_lines(char *fd_name, t_game *game)
{
	int		fd;
	char	*map;
	int		i;

	i = 0;
	fd = open(fd_name, O_RDONLY);
	while (i < game->start_map_line)
	{
		map = get_next_line(fd);
		free(map);
		i++;
	}
	return (fd);
}
