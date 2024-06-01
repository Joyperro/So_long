/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:25:43 by dclement          #+#    #+#             */
/*   Updated: 2024/03/18 15:07:57 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	is_valid_file(int argc, char **argv)
{
	char	*is_ber_file;

	if (argc != 2)
	{
		perror("Just one argument, please!");
		return (FALSE);
	}
	is_ber_file = ft_strchr(argv[1], '.');
	if (!is_ber_file)
	{
		error("Invalid file.");
		return (FALSE);
	}
	if (ft_strncmp(is_ber_file, ft_strchr(argv[1], '.'), 3) != 0)
	{
		error("Introduce a .ber file, please");
		return (FALSE);
	}
	return (TRUE);
}

static int	line_count(char *file)
{
	int		linecount;
	int		fd;
	int		read_bytes;
	char	c;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (-1);
	linecount = 1;
	while (TRUE)
	{
		read_bytes = read(fd, &c, 1);
		if (read_bytes == 0)
			break ;
		if (read_bytes < 0)
			return (-1);
		if (c == '\n')
			linecount++;
	}
	close(fd);
	return (linecount);
}

static char	**alloc_columns(char *file)
{
	char	**map;
	int		num_lines;

	num_lines = line_count(file);
	if (num_lines <= 0)
	{
		error("Problem opening or reading the file.");
		return (NULL);
	}
	map = malloc(sizeof(char *) * num_lines + 1);
	if (!map)
	{
		error("Malloc error creating map.");
		return (NULL);
	}
	return (map);
}

char	**map_reader(char *file)
{
	char	**map;
	int		fd;
	int		i;

	map = alloc_columns(file);
	if (map == NULL)
		return (NULL);
	fd = open(file, O_RDONLY);
	i = 0;
	while (TRUE)
	{
		map[i] = get_next_line(fd);
		if (map [i] == NULL)
			break ;
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
