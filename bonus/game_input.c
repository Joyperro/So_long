/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:24:43 by dclement          #+#    #+#             */
/*   Updated: 2024/04/19 12:44:10 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_bool	move_to(t_game *game, t_tile *tile)
{
	if (tile->type == EMPTY)
		move_to_empty(game, tile);
	else if (tile->type == COLLECTABLE)
		pick_collectable(game, tile);
	else if (tile->type == EXIT && game->ac_collectables == 0)
		move_to_exit(game);
	else
		return (FALSE);
	return (TRUE);
}

void	action_anim(t_player *player)
{
	player->framecount = 0;
	player->actual_img = player->running_img;
}

int	input(int key, t_game *game)
{
	t_bool	moved;

	if (key == ESC)
		end_program(game);
	if (game->player.tile == NULL)
		return (0);
	if (key == KEY_UP)
		moved = move_to(game, game->player.tile->up);
	else if (key == KEY_DOWN)
		moved = move_to(game, game->player.tile->down);
	else if (key == KEY_RIGHT)
		moved = move_to(game, game->player.tile->right);
	else if (key == KEY_LEFT)
		moved = move_to(game, game->player.tile->left);
	else
		return (0);
	if (moved)
		ft_printf("Moves -> %d\n", ++game->num_moves);
	return (1);
}
