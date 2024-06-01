/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:05:07 by dclement          #+#    #+#             */
/*   Updated: 2024/04/19 12:42:42 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	open_player_img(t_game *game)
{
	game->player.idle_img = mlx_xpm_file_to_image(game->mlx_ptr,
			PLAYER_SP, &game->img_size.x, &game->img_size.y);
	game->player.idle_img_1 = mlx_xpm_file_to_image(game->mlx_ptr,
			PLAYER_IDLE, &game->img_size.x, &game->img_size.y);
	game->player.running_img = mlx_xpm_file_to_image(game->mlx_ptr,
			RUNNING_SP, &game->img_size.x, &game->img_size.y);
	game->player.actual_img = game->player.idle_img;
}

static void	open_door_img(t_game *game)
{
	game->door_close_img = mlx_xpm_file_to_image(game->mlx_ptr,
			EXIT_SP, &game->img_size.x, &game->img_size.y);
	game->door_open_img = mlx_xpm_file_to_image(game->mlx_ptr,
			EXIT2, &game->img_size.x, &game->img_size.y);
}

static void	open_wall_img(t_game *game)
{
	game->wall_img = mlx_xpm_file_to_image(game->mlx_ptr,
			WALL_SP, &game->img_size.x, &game->img_size.y);
}

void	open_img(t_game *game)
{
	open_player_img(game);
	open_door_img(game);
	open_wall_img(game);
	open_floor_img(game);
	open_collectible_img(game);
}
