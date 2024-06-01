/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:43:44 by dclement          #+#    #+#             */
/*   Updated: 2024/01/24 18:33:16 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	int		srcsize;

	i = 0;
	srcsize = ft_strlen(src);
	if (dstsize == 0)
		return (srcsize);
	else
	{
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
	}
	dst[i] = '\0';
	return (srcsize);
}
/*
int	main(void)
{
	char src[] = "Hello, World";

	char dst1[15];
	char dst2[15]

	size_t n;

	n = ft_strlcpy(dst1, src, 14);
	printf("Mi strlcpy:	%zu cadena: %s\n", n, dst1);
	n = strlcpy(dst2, src, 14);
	printf("strlcpy : %zu cadena: %s", n, dst2);
	return (0);
}*/