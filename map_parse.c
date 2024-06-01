/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:47:10 by dclement          #+#    #+#             */
/*   Updated: 2024/04/05 16:53:55 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_mapcheckdata	init_datacheck(char **map)
{
	t_mapcheckdata	data;

	data.size.x = ft_strlen(map[0]) - 1;
	data.size.y = map_linecount(map);
	data.v_player = FALSE;
	data.v_exit = FALSE;
	data.v_collectable = FALSE;
	data.point.x = 0;
	data.point.y = 0;
	return (data);
}

static int	tile_check(char **map, t_mapcheckdata *data, t_game *game)
{
	int	x;
	int	y;

	x = data->point.x;
	y = data->point.y;
	if (!is_valid_char(map[y][x]))
		return (error("invalid characters"));
	if (map[y][x] == 'P' && data->v_player == FALSE)
		data->v_player = TRUE;
	else if (map[y][x] == 'P' && data->v_player == TRUE)
		return (error("there can only be one player 'P'"));
	if (map[y][x] == 'E')
		data->v_exit = TRUE;
	else if (map[y][x] == 'E' && data->v_exit == TRUE)
		return (error("there can only be one exit 'E'"));
	if (!is_valid_border(map[y][x], data->point, data->size))
		return (error("must be surrounded by walls '1'"));
	if (map[y][x] == 'C')
	{
		game->og_collectables += 1;
		data->v_collectable = TRUE;
	}
	return (TRUE);
}

int	is_valid_map(char **map, t_game *game)
{
	t_mapcheckdata	data;
	t_bool			valid;

	data = init_datacheck(map);
	valid = TRUE;
	if (data.size.y == data.size.x)
		return (error("Map has to be rectangular"));
	while (map[data.point.y] != NULL)
	{
		data.point.x = 0;
		while (map[data.point.y][data.point.x] != '\0')
		{
			if (map[data.point.y][data.point.x] == '\n')
				break ;
			if (tile_check(map, &data, game) == FALSE)
				valid = FALSE;
			data.point.x++;
		}
		data.point.y++;
	}
	if ((valid == TRUE && !initialize_flood(map, game))
		|| (data.v_player == FALSE || data.v_collectable == FALSE
			|| data.v_exit == FALSE))
		return (error("Missing key characters or valid path"));
	return (valid);
}
