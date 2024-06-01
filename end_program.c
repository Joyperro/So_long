/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:59:23 by dclement          #+#    #+#             */
/*   Updated: 2024/04/02 13:26:29 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tilemap(t_game *game)
{
	t_tile	**tilemap;
	int		i;

	tilemap = game->tilemap;
	i = 0;
	while (tilemap[i] != NULL)
	{
		free(tilemap[i]);
		i++;
	}
	free(tilemap);
}

void	remove_player(t_game *game)
{
	game->player.tile->type = EMPTY;
	game->player.tile = NULL;
}

int	end_program(t_game *game)
{
	free_tilemap(game);
	game->tilemap = NULL;
	exit(0);
}
