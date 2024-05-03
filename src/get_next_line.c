/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbardeau <fbardeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:06:05 by fbardeau          #+#    #+#             */
/*   Updated: 2023/09/05 16:53:14 by fbardeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_bzero(char *s, size_t n)
{
	size_t			j;

	if (!n)
		return (NULL);
	j = 0;
	while (j < n)
	{
		((unsigned char *)s)[j] = 0;
		j++;
	}
	return (s);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	while (i < (size * count))
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_read_next_line(int fd, char *string)
{
	char	*buffer;
	int		read_byte;
	int		i;

	i = 0;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	read_byte = 1;
	while (read_byte)
	{
		ft_bzero(buffer, BUFFER_SIZE);
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte < 0)
		{
			free(buffer);
			return (NULL);
		}
		string = ft_strjoin(string, buffer, i);
		if (ft_strchr(string, '\n'))
			break ;
	}
	free(buffer);
	return (string);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*next;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (read(fd, 0, 0) < 0)
	{
		free(next);
		next = NULL;
		return (NULL);
	}
	next = ft_read_next_line(fd, next);
	if (!next)
		return (NULL);
	line = ft_deletetab(next);
	next = ft_save_next_line(next, i);
	return (line);
}
