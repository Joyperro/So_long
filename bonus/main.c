/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:10:59 by dclement          #+#    #+#             */
/*   Updated: 2024/04/19 12:50:10 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// 	atexit(ultima);
// static void	ultima(void)
// {
// 	system("leaks so_long");
// }
int	main(int argc, char **argv)
{
	t_game	game;

	if (!start(&game, argc, argv))
		return (0);
	mlx_hook(game.win_ptr, 2, 0, input, (void *)&game);
	mlx_loop_hook(game.mlx_ptr, update, (void *)&game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
