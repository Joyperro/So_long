/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_datacheck.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:55:08 by dclement          #+#    #+#             */
/*   Updated: 2024/04/19 12:41:32 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_linecount(char **map)
{
	int	count;

	count = 0;
	while (map[count])
		count++;
	return (count);
}

int	is_valid_char(char c)
{
	if (c == 'P' || c == 'E' || c == 'C' || c == '1'
		|| c == '0')
		return (TRUE);
	return (FALSE);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
