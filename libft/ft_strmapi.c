/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:11:21 by dclement          #+#    #+#             */
/*   Updated: 2024/01/25 16:41:05 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	if (!s || !(*f))
		return (NULL);
	str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < (unsigned int)ft_strlen(s))
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}
/*
char	f(unsigned int i, char c)
{
	c = c + i;
	return (c);
}
int main()
{
	const char s[] = "Hola mundo";
	char *s1;

	s1 = ft_strmapi(s, &f);
	printf("resultado: %s", s1);
	free(s1);
	return (0);
}*/