/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_border_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:19:48 by dclement          #+#    #+#             */
/*   Updated: 2024/03/15 20:27:19 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_border(char c, t_vector point, t_vector size)
{
	if ((point.y == 0 || point.x == 0)
		|| (point.y == size.y - 1 || point.x == size.x - 1))
		if (c != '1')
			return (FALSE);
	return (TRUE);
}
