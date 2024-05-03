/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbardeau <fbardeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:06:19 by fbardeau          #+#    #+#             */
/*   Updated: 2023/09/05 16:53:12 by fbardeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strlen(char *c)
{
	int	i;

	i = -1;
	if (!c)
		return (0);
	while (c[++i])
		;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2, int i)
{
	char	*str;
	int		j;

	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	if (!s1 || !s2)
		return (NULL);
	str = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!str)
		return (NULL);
	j = 0;
	while (s1[i])
	{
		str[i] = (char)s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = (char)s2[j];
		i++;
		j++;
	}
	free (s1);
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

char	*ft_deletetab(char *str)
{
	int		i;
	int		j;
	char	*string;

	i = 0;
	if (!str || str[0] == '\0')
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	string = ft_calloc(i + 1, sizeof(char));
	if (!string)
	{
		return (NULL);
	}
	j = 0;
	while (j < i)
	{
		string[j] = str[j];
		j++;
	}
	return (string);
}

char	*ft_save_next_line(char *str, int i)
{
	int		j;
	char	*string;

	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	string = ft_calloc(ft_strlen(str) - i + 1, sizeof(char));
	if (!string)
		return (NULL);
	i++;
	while (str[i])
	{
		string[j] = str[i];
		j++;
		i++;
	}
	free(str);
	return (string);
}
