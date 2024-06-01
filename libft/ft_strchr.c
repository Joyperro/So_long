/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:43:19 by dclement          #+#    #+#             */
/*   Updated: 2024/01/22 16:48:34 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	else
		return (NULL);
}
/*
int	main(void)
{
	const char *str = "Hello, World!";
	int target_char = '';

	char *my_result = ft_strchr(str, target_char);
	printf("My ft_strchr result: 	%s\n", my_result ? my_result : "NULL");

	char *original_result = strchr(str, target_char);
	printf("Original strchr result: %s\n",
		original_result ? original_result : "NULL");

	if ((my_result == NULL && original_result == NULL) || (strcmp(my_result,
				original_result) == 0))
		printf("Results match!\n");
	else
		printf("Results do not match.\n");

	return (0);
}*/