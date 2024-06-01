/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:54:13 by dclement          #+#    #+#             */
/*   Updated: 2024/04/02 14:03:39 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error(const char *str)
{
	ft_printf("Error:\n %s", str);
	return (0);
}

void	*null_err(const char *str)
{
	ft_printf("Error:\n %s", str);
	return (0);
}

void	free_visited(t_game *game, int i)
{
	while (i >= 0)
	{
		free(game->visited[i]);
		i--;
	}
	free(game->visited);
}
