/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbardeau <fbardeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:01:27 by fbardeau          #+#    #+#             */
/*   Updated: 2023/09/21 12:44:11 by fbardeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_name_fd(char **argv)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	str = ft_strdup(".cub");
	j = 0;
	len = ft_strlen(argv[1]);
	i = len - 4;
	while (i < len)
	{
		if (argv[1][i] != str[j])
			ft_exit_fail('f');
		j++;
		i++;
	}
	free(str);
	return (0);
}

int	ft_check_error(int height, int width, char **map)
{
	if (height == width)
		ft_exit_fail('c');
	ft_check_border_map(height, width, map);
	return (0);
}

void	ft_check_border_map(int height, int width, char **map)
{
	int	i;

	i = -1;
	while (i++ < width - 1)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			ft_exit_fail('b');
	}
	i = -1;
	while (i++ < height - 1)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			ft_exit_fail('b');
	}
}

int	ft_cmp(char s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		if (s1 == s2[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_void(void)
{
}
