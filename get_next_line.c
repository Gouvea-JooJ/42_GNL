/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopedro2 <jopedro2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:57:22 by jopedro2          #+#    #+#             */
/*   Updated: 2022/08/05 21:16:58 by jopedro2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fd_read(int fd, char *buffer)
{
	char	*reader;
	int		counter;

	reader = malloc(sizeof (char) * (BUFFER_SIZE + 1));
	if (!reader)
		return (NULL);
	counter = 1;
	while (!ft_strchr(buffer, '\n') && counter != 0)
	{
		counter = read (fd, reader, BUFFER_SIZE);
		if (counter < 0)
		{
			free (reader);
			return (NULL);
		}
		reader[counter] = '\0';
		buffer = ft_strjoin(buffer, reader);
	}
	free (reader);
	return (buffer);
}

char	*line_cutter(char *buffer)
{
	char	*holder;
	int		i;

	i = 0;
	if (buffer[i] == '\0')
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	holder = ft_substr(buffer, 0, i + if_null(buffer));
	if (!holder)
	{
		free (holder);
		return (NULL);
	}
	return (holder);
}

char	*clear(char *buffer)
{
	int		i;
	int		n;
	char	*holder;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free (buffer);
		return (NULL);
	}
	holder = malloc(sizeof (char) * (ft_strlen(buffer) - i + 1));
	if (!holder)
	{
		free (holder);
		return (NULL);
	}
	i++;
	n = 0;
	while (buffer[i] != '\0')
		holder[n++] = buffer[i++];
	holder[n] = '\0';
	free (buffer);
	return (holder);
}

char	*get_next_line(int fd)
{
	char		*ret;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = fd_read(fd, buffer);
	if (!buffer)
		return (NULL);
	ret = line_cutter(buffer);
	buffer = clear(buffer);
	return (ret);
}
