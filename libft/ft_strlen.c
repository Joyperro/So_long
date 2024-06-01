/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:58:40 by dclement          #+#    #+#             */
/*   Updated: 2024/02/12 16:34:33 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
/*
int	main(void)
{
	char	str[] = "Hola mundo";
	int		n;

	n = strlen(str);
	printf("Longitud:	%d\n", n);
	n = ft_strlen(str);
	printf("Longitud mío: %d", n);
	return (0);
}*/
