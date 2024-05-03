/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuzmin <vkuzmin@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:50:28 by fbardeau          #+#    #+#             */
/*   Updated: 2023/10/10 18:08:56 by vkuzmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_img(t_game *game, char *name, t_img *texture)
{
	texture->img = mlx_xpm_file_to_image(game->mlx_ptr, name, &texture->wid, \
			&texture->hei);
	if (!texture->img)
		exit(EXIT_FAILURE);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp, \
			&texture->line_len, &texture->endian);
	return (texture->img);
}

void	put_pixel_to_img(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

int	get_texture_color(t_img *texture, int x, int y)
{
	char	*pixel;
	int		color;

	if (x < 0 || x >= texture->wid || y < 0 || y >= texture->hei)
		return (0);
	pixel = texture->addr + (y * texture->line_len + x * (texture->bpp / 8));
	color = *(unsigned int *)pixel;
	return (color);
}
