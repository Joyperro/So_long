/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:39:25 by dclement          #+#    #+#             */
/*   Updated: 2024/04/19 12:52:21 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game *game);
t_tile	**map_init(int argc, char **argv, t_game *game);

t_tile	**map_init(int argc, char **argv, t_game *game)
{
	char	**map;
	t_tile	**tilemap;

	if (!is_valid_file(argc, argv))
		return (NULL);
	map = map_reader(argv[1]);
	if (!map)
		return (NULL);
	if (!is_valid_map(map, game))
	{
		free_map(map);
		return (NULL);
	}
	tilemap = tilemap_generator(map, game);
	free_map(map);
	if (!tilemap)
		return (NULL);
	return (tilemap);
}

void	game_init(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			(game->win_size.x / TILE_SIZE) * TILE_SIZE,
			(game->win_size.y / TILE_SIZE) * TILE_SIZE,
			"so_long");
	mlx_hook(game->win_ptr, 17, 0, end_program, game);
	open_img(game);
}

t_bool	start(t_game *game, int argc, char **argv)
{
	game->ac_collectables = 0;
	game->og_collectables = 0;
	game->num_moves = 0;
	game->tilemap = map_init(argc, argv, game);
	if (game->tilemap == NULL)
		return (FALSE);
	game_init(game);
	return (TRUE);
}
