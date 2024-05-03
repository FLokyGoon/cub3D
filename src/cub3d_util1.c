/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_util1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmin <vkuzmin@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:33:54 by vkuzmin           #+#    #+#             */
/*   Updated: 2023/10/13 00:57:52 by vkuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_width(char *fd_name, t_game *game)
{
	char	*map;
	int		width;
	int		fd;
	int		i;

	i = 0;
	width = 0;
	fd = open_and_skip_initial_lines(fd_name, game);
	while (1)
	{
		map = get_next_line(fd);
		if (map == NULL)
		{
			free(map);
			break ;
		}
		width = ft_strlen(map);
		free (map);
	}
	close(fd);
	return (width);
}

char	**ft_copy_map(char *fd_name, int height, int width, t_game *game)
{
	int		i;
	int		fd;
	char	**copy_map;
	char	*buff;

	i = 0;
	(void)width;
	copy_map = ft_calloc(sizeof(char *), height + 1);
	fd = open(fd_name, O_RDONLY);
	while (i < game->start_map_line)
	{
		buff = get_next_line(fd);
		free (buff);
		i++;
	}
	i = 0;
	while (i < height)
	{
		copy_map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	copy_map[height] = 0;
	return (copy_map);
}

char	*ft_strdup(char *s1)
{
	size_t	i;
	char	*copy;

	i = 0;
	copy = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!copy)
		return (NULL);
	while (s1[i])
	{
		copy[i] = ((char *)s1)[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;
	int	count;

	count = 0;
	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] == '-' || str[i + 1] == '+')
			return (0);
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i++] - 48;
	}
	return (res * sign);
}
