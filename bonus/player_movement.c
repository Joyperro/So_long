/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:22:03 by dclement          #+#    #+#             */
/*   Updated: 2024/04/19 12:43:17 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_to_empty(t_game *game, t_tile *tile)
{
	tile->type = PLAYER;
	if (game->player.tile->type != EXIT)
	{
		action_anim(&game->player);
		game->player.tile->type = EMPTY;
	}
	game->player.tile = tile;
}

void	pick_collectable(t_game *game, t_tile *tile)
{
	tile->type = EMPTY;
	game->ac_collectables--;
	move_to_empty(game, tile);
}

void	move_to_exit(t_game *game)
{
	remove_player(game);
	game->ac_collectables = -1;
	end_program(game);
}
