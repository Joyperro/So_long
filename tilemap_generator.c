/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilemap_generator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:26:56 by dclement          #+#    #+#             */
/*   Updated: 2024/03/21 16:15:32 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_tile	**alloc_tilemap(char **map)
{
	t_tile	**tilemap;
	int		i;

	tilemap = malloc(sizeof(t_tile *) * map_linecount(map) + 1);
	if (!tilemap)
		return (NULL);
	i = 0;
	while (map[i] != NULL)
	{
		tilemap[i] = malloc(sizeof(t_tile) * ft_strlen(map[i]) + 1);
		if (tilemap == NULL)
		{
			while (i > 0)
				free(tilemap[--i]);
			return (NULL);
		}
		i++;
	}
	return (tilemap);
}

static t_tiletype	define_tile(char define)
{
	if (define == '1')
		return (WALL);
	if (define == 'P')
		return (PLAYER);
	if (define == 'E')
		return (EXIT);
	if (define == 'C')
		return (COLLECTABLE);
	return (EMPTY);
}

static void	setup_tile(t_tile **tilemap, int x, int y)
{
	tilemap[y][x].og_type = tilemap[y][x].type;
	tilemap[y][x].position.x = x * TILE_SIZE;
	tilemap[y][x].position.y = y * TILE_SIZE;
	if (y != 0)
		tilemap[y][x].up = &tilemap[y - 1][x];
	if (tilemap[y + 1] != NULL)
		tilemap[y][x].down = &tilemap[y + 1][x];
	if (x != 0)
		tilemap[y][x].left = &tilemap[y][x - 1];
	tilemap[y][x].right = &tilemap [y][x + 1];
}

static void	set_gamevars(t_tile *tile, t_game *game)
{
	if (tile->type == PLAYER)
		game->player.tile = tile;
	else if (tile->type == COLLECTABLE)
		game->ac_collectables++;
}

t_tile	**tilemap_generator(char **map, t_game *game)
{
	t_tile	**tilemap;
	int		x;
	int		y;

	tilemap = alloc_tilemap(map);
	if (!tilemap)
		return (null_err("malloc error in tilemap."));
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			tilemap[y][x].type = define_tile(map[y][x]);
			setup_tile(tilemap, x, y);
			set_gamevars(&tilemap[y][x], game);
			x++;
		}
		tilemap[y][x].type = 0;
		y++;
	}
	tilemap[y] = NULL;
	game->win_size.x = x * TILE_SIZE;
	game->win_size.y = y * TILE_SIZE;
	return (tilemap);
}
