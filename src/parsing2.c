/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbardeau <fbardeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:16:38 by fbardeau          #+#    #+#             */
/*   Updated: 2023/10/18 10:17:12 by fbardeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_textures1(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->start_map_line)
	{
		if (game->file_copy[i][0] == 'N' && game->file_copy[i][1] == 'O'
			&& game->file_copy[i][2] == ' ')
		{
			game->north_texture_path = ft_strdup(game->file_copy[i] + 3);
		}
		if (game->file_copy[i][0] == 'E' && game->file_copy[i][1] == 'A'
			&& game->file_copy[i][2] == ' ')
		{
			game->east_texture_path = ft_strdup(game->file_copy[i] + 3);
		}
		i++;
	}
}

void	get_textures2(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->start_map_line)
	{
		if (game->file_copy[i][0] == 'W' && game->file_copy[i][1] == 'E'
			&& game->file_copy[i][2] == ' ')
		{
			game->west_texture_path = ft_strdup(game->file_copy[i] + 3);
		}
		if (game->file_copy[i][0] == 'S' && game->file_copy[i][1] == 'O'
			&& game->file_copy[i][2] == ' ')
		{
			game->south_texture_path = ft_strdup(game->file_copy[i] + 3);
		}
		i++;
	}
}

void	check_end_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '.')
	{
		i++;
	}
	if (str[i + 1] == 'x' && str[i + 2] == 'p' && str[i + 3] == 'm')
	{
		if (str[i + 4] != '\n')
			ft_exit_fail('a');
	}
	if (str[i] != '.' || str[i + 1] != 'x'
		|| str[i + 2] != 'p' || str[i + 3] != 'm')
	{
		ft_exit_fail('a');
	}
}

void	remove_trailing_spaces(char *str)
{
	int	len;

	len = ft_strlen(str);
	while (len > 0 && (str[len - 1] == ' ' || str[len - 1] == '\t'
			|| str[len - 1] == '\n'))
		len--;
	str[len] = '\n';
	str[len + 1] = '\0';
}

void	remove_char(char *str, char target)
{
	char	*src;
	char	*dst;

	dst = str;
	src = str;
	while (*src)
	{
		*dst = *src++;
		dst += (*dst != target);
	}
	*dst = '\0';
}
