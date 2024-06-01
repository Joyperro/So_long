/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:48:21 by marvin            #+#    #+#             */
/*   Updated: 2024/03/23 12:48:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_bool	is_invalid_exit(char **map, int x, int y, t_game *game)
{
	if (map[y][x] == 'E' && ((map[y + 1][x] == '1' && map[y - 1][x] == '1')
		&& (map[y][x + 1] == '0' && map[y][x - 1] == '0')
		&& game->og_collectables != 0))
		return (TRUE);
	if (map[y][x] == 'E' && ((map[y][x + 1] == '1' && map[y][x - 1] == '1')
		&& (map[y + 1][x] == '0' && map[y - 1][x] == '0')
		&& game->og_collectables != 0))
		return (TRUE);
	if (map[y][x] == 'E' && ((map[y + 1][x] == '0' && map[y][x - 1] == '0')
		|| (map[y + 1][x] == '0' && map[y][x + 1] == '0'))
		&& game->og_collectables != 0
		&& (map[y + 1][x + 1] == '1' || map[y + 1][x - 1] == '1'))
		return (TRUE);
	return (FALSE);
}

static t_bool	flood_fill(char **map, int x, int y, t_game *game)
{
	if (x < 0 || y < 0 || x >= (int)ft_strlen(map[0])
		|| y >= map_linecount(map))
		return (FALSE);
	if (map[y][x] == '1' || game->visited[y][x] == TRUE)
		return (FALSE);
	if (is_invalid_exit(map, x, y, game))
		return (FALSE);
	game->visited[y][x] = TRUE;
	if (map[y][x] == 'E')
	{
		game->flag = 1;
		if (game->og_collectables > 0)
			return (FALSE);
	}
	if (map[y][x] == 'C')
		game->og_collectables--;
	if (game->og_collectables == 0 && game->flag == 1)
		return (TRUE);
	return (flood_fill(map, x + 1, y, game)
		|| flood_fill(map, x - 1, y, game)
		|| flood_fill(map, x, y + 1, game)
		|| flood_fill(map, x, y - 1, game));
}

static t_bool	**set_visited(char **map, t_game *game)
{
	int		i;
	int		j;

	game->visited = malloc(sizeof(t_bool *) * map_linecount(map));
	if (!game->visited)
		return (NULL);
	i = 0;
	while (i < map_linecount(map))
	{
		game->visited[i] = malloc(sizeof(t_bool) * ft_strlen(map[0]));
		if (!game->visited[i])
		{
			free_visited(game, i);
			return (NULL);
		}
		j = 0;
		while (j < (int)ft_strlen(map[0]))
		{
			game->visited[i][j] = FALSE;
			j++;
		}
		i++;
	}
	return (game->visited);
}

t_bool	initialize_flood(char **map, t_game *game)
{
	int		i;
	int		j;

	game->visited = set_visited(map, game);
	if (!game->visited)
		return (FALSE);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
			{
				if (!flood_fill(map, j, i, game))
					break ;
				else
					return (TRUE);
			}
			j++;
		}
		i++;
	}
	free_visited(game, map_linecount(map) - 1);
	return (FALSE);
}
