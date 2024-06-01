/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:54:10 by dclement          #+#    #+#             */
/*   Updated: 2024/01/21 19:45:00 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*byte_ptr;
	size_t			i;

	if (n == 0)
		return ;
	i = 0;
	byte_ptr = (unsigned char *)str;
	while (i < n)
	{
		*byte_ptr = 0;
		byte_ptr++;
		i++;
	}
}
