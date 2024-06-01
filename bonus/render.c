/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:40:52 by dclement          #+#    #+#             */
/*   Updated: 2024/04/06 20:29:01 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_image(t_tile tile, t_game game, t_vector pos)
{
	if (tile.type == WALL)
		mlx_put_image_to_window(game.mlx_ptr, game.win_ptr,
			game.wall_img, pos.x, pos.y);
	else if (tile.type == EXIT)
	{
		if (game.ac_collectables != 0)
			mlx_put_image_to_window(game.mlx_ptr, game.win_ptr,
				game.door_close_img, pos.x, pos.y);
		else if (game.ac_collectables == 0)
			mlx_put_image_to_window(game.mlx_ptr, game.win_ptr,
				game.door_open_img, pos.x, pos.y);
	}
	else if (tile.type == PLAYER)
		mlx_put_image_to_window(game.mlx_ptr, game.win_ptr,
			game.player.actual_img, pos.x, pos.y);
	else if (tile.type == COLLECTABLE)
		mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.key_img,
			pos.x, pos.y);
	else if (tile.type == EMPTY)
		mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.floor_img,
			pos.x, pos.y);
	else if (tile.type == ENEMY)
		mlx_put_image_to_window(game.mlx_ptr, game.win_ptr,
			game.enemy_img, pos.x, pos.y);
}

static void	draw_text(t_game game)
{
	char	*str;

	str = ft_itoa(game.num_moves);
	if (game.ac_collectables >= 0)
		mlx_string_put(game.mlx_ptr, game.win_ptr,
			game.win_size.x - TILE_SIZE,
			game.win_size.y - TILE_SIZE, -1, str);
	else
		mlx_string_put(game.mlx_ptr, game.win_ptr,
			game.win_size.x - TILE_SIZE / 2,
			game.win_size.y - TILE_SIZE / 2, 15921152, str);
	free(str);
}

void	render(t_game game)
{
	t_tile	tile;
	int		x;
	int		y;

	mlx_clear_window(game.mlx_ptr, game.win_ptr);
	mlx_put_image_to_window(game.mlx_ptr, game.win_ptr,
		game.floor_img, 0, 0);
	y = 0;
	while (game.tilemap[y] != NULL)
	{
		x = 0;
		while (game.tilemap[y][x].type != 0)
		{
			tile = game.tilemap[y][x];
			draw_image(tile, game, tile.position);
			x++;
		}
		y++;
	}
	draw_text(game);
}
