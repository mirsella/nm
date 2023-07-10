/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:54:00 by mirsella          #+#    #+#             */
/*   Updated: 2023/02/28 15:40:51 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"
#include "unistd.h"

static char	*ft_s1join(char *s1, char *s2)
{
	char	*str;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (free(s1), NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	free(s1);
	return (str);
}

static char	*read_next_line(int fd, char *storage)
{
	char	*buffer;
	int		ret;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	ret = 1;
	while (ret > 0 && !ft_strchr(buffer, '\n'))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret > 0)
		{
			buffer[ret] = '\0';
			storage = ft_s1join(storage, buffer);
		}
	}
	free(buffer);
	if (ret == -1)
		return (NULL);
	return (storage);
}

static char	*get_line_from_buffer(char *storage)
{
	char	*str;
	int		i;

	i = 0;
	if (!storage[0])
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, storage, i + 1);
	return (str);
}

char	*get_end_of_buffer(char *storage)
{
	char	*str;
	int		i;

	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\0')
		return (NULL);
	i++;
	str = malloc(sizeof(char) * (ft_strlen(storage) - i + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, storage + i, ft_strlen(storage) - i + 1);
	return (str);
}

char	*ft_get_next_line(int fd, int freee)
{
	static char	*storage;
	char		*line;
	char		*tmp;

	if (freee == 1)
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!storage || (storage && !ft_strchr(storage, '\n')))
		storage = read_next_line(fd, storage);
	if (!storage)
		return (NULL);
	line = get_line_from_buffer(storage);
	tmp = get_end_of_buffer(storage);
	free(storage);
	storage = tmp;
	return (line);
}
