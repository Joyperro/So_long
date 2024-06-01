/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:43:10 by dclement          #+#    #+#             */
/*   Updated: 2024/01/24 18:02:15 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*source;
	char		*backdst;
	const char	*backsrc;

	dest = dst;
	source = src;
	if (dst == NULL && src == NULL)
		return (NULL);
	else if (dest < source)
	{
		while (len--)
			*dest++ = *source++;
	}
	else
	{
		backdst = dest + (len - 1);
		backsrc = source + (len - 1);
		while (len--)
			*backdst-- = *backsrc--;
	}
	return (dst);
}
/*
int	main(void)
{
	char buffer[] = "0123456789101112";
	char *source = buffer;
	char *destination = buffer + 1;

	printf("Source original: %s\n", source);
	printf("Destino original: %s\n", destination);
	memmove(destination, source, 13);
	printf("Standard memmove: %s\n", buffer);

	strcpy(buffer, "0123456789101112");
	source = buffer;
	destination = buffer + 1;

	ft_memmove(destination, source, 13);
	printf("Your ft_memmove: %s\n", buffer);

	return (0);
}*/