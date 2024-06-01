/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:01:05 by dclement          #+#    #+#             */
/*   Updated: 2024/03/15 19:43:55 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_line(int fd, char *aux, char *buffer)
{
	ssize_t	num_bytes;
	char	*tmp;

	num_bytes = 1;
	while (num_bytes > 0)
	{
		num_bytes = read(fd, aux, BUFFER_SIZE);
		if (num_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		else if (num_bytes == 0)
			break ;
		aux[num_bytes] = '\0';
		if (!buffer)
			buffer = ft_strdup("");
		tmp = buffer;
		buffer = ft_strjoin(tmp, aux);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(aux, '\n'))
			break ;
	}
	return (buffer);
}

static char	*ft_leftover(char *line)
{
	char	*tmp;
	ssize_t	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[1] == 0 || line[i] == 0)
		return (NULL);
	tmp = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*tmp == 0)
	{
		free(tmp);
		return (NULL);
	}
	line[i + 1] = '\0';
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*aux;
	char		*line;

	aux = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
	{
		free(buffer);
		free(aux);
		buffer = NULL;
		aux = NULL;
		return (NULL);
	}
	if (!aux)
		return (NULL);
	line = ft_read_line(fd, aux, buffer);
	if (!line)
	{
		free(aux);
		return (NULL);
	}
	free(aux);
	aux = NULL;
	buffer = ft_leftover(line);
	return (line);
}
