/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:55:42 by dclement          #+#    #+#             */
/*   Updated: 2024/01/22 18:58:29 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dest_ptr;
	const unsigned char	*source_ptr;
	size_t				i;

	if (dst == NULL && src == NULL)
		return (dst);
	dest_ptr = (unsigned char *)dst;
	source_ptr = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		*dest_ptr = *source_ptr;
		dest_ptr++;
		source_ptr++;
		i++;
	}
	return (dst);
}
