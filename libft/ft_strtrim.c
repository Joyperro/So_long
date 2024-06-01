/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:43:58 by dclement          #+#    #+#             */
/*   Updated: 2024/01/25 16:32:16 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_findch(char s, const char *set)
{
	int	j;

	j = 0;
	while (set[j] != '\0')
	{
		if (s == set[j])
			return (1);
		else
			j++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		index;
	int		j;
	int		size;
	char	*s2;

	if (!s1 || !set)
		return (NULL);
	index = 0;
	size = (int)ft_strlen(s1);
	while (s1[index] != '\0' && ft_findch(s1[index], set))
		index++;
	while (size > 0 && ft_findch(s1[size - 1], set))
		size--;
	if ((size - index) < 0)
		s2 = ft_calloc((size - (-index)) + 1, sizeof(char));
	else
		s2 = ft_calloc((size - index) + 1, sizeof(char));
	if (!s2)
		return (NULL);
	j = 0;
	while (index < size)
		s2[j++] = s1[index++];
	s2[j] = '\0';
	return (s2);
}
/*
int	main(void)
{
	char s1[] = "          ";
	char set[] = " ";
	char *s2;

	printf("Cadena antes del recorte: %s\n", s1);
	s2 = ft_strtrim(s1, set);
	printf("Cadena después del recorte: %s", s2);
	free(s2);
	return(0);
}*/