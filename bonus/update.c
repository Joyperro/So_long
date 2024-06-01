/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:09:14 by dclement          #+#    #+#             */
/*   Updated: 2024/03/18 13:06:27 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	player_anim(t_player *player)
{
	if (player->actual_img == player->idle_img
		&& player->framecount >= player->idle_frames)
		player->actual_img = player->idle_img;
	else if (player->framecount == player->idle_frames)
		player->actual_img = player->idle_img_1;
	else if (player->framecount >= player->idle_frames * 2)
	{
		player->actual_img = player->idle_img;
		player->framecount = 0;
	}
	player->framecount += 1;
}

int	update(t_game *game)
{
	player_anim(&game->player);
	render(*game);
	return (1);
}
