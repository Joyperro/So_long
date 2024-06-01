/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:44:02 by dclement          #+#    #+#             */
/*   Updated: 2024/02/25 14:04:49 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*sub_s;
	size_t			index;

	if (!s)
		return (NULL);
	index = 0;
	if ((unsigned int)ft_strlen(s) <= start)
		return (ft_strdup(""));
	else if (ft_strlen(&s[start]) <= len)
		sub_s = malloc(ft_strlen(&s[start]) + 1);
	else
		sub_s = malloc(len + 1);
	if (!sub_s)
		return (NULL);
	while (index < len && s[start + index] != '\0')
	{
		sub_s[index] = s[start + index];
		index++;
	}
	sub_s[index] = '\0';
	return (sub_s);
}

/*
int	main(void)
{
	char str[] = "FULL BULLSHIT";
	char *sub_s;

	sub_s = ft_substr(str, 400, 20);
	printf("Subcadena resultante: %s", sub_s);
	free(sub_s);
	return (0);
}*/