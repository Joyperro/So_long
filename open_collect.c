/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_collect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:35:44 by dclement          #+#    #+#             */
/*   Updated: 2024/03/18 13:03:15 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_collectible_img(t_game *game)
{
	game->key_img = mlx_xpm_file_to_image(game->mlx_ptr,
			COLLECTABLE_SP, &game->img_size.x, &game->img_size.y);
}

void	open_floor_img(t_game *game)
{
	game->floor_img = mlx_xpm_file_to_image(game->mlx_ptr,
			FLOOR, &game->img_size.x, &game->img_size.y);
}
