/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:42:33 by dclement          #+#    #+#             */
/*   Updated: 2024/01/25 20:14:58 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count != 0 && size > SIZE_MAX / count)
		return (NULL);
	ptr = malloc(count * size);
	if (ptr)
		ft_bzero(ptr, count * size);
	return (ptr);
}
/*
int	main(void) {
	size_t count = 15;
	size_t size = sizeof(int);
	size_t i = 0;
	int *arr_ft_calloc = (int *)ft_calloc(count, size);

	if (arr_ft_calloc) {
		printf("Memoria colocada usando ft_calloc:\n");
		while (i < count)
		{
			printf("%d ", arr_ft_calloc[i]);
			i++;
		}
		printf("\n");
		free(arr_ft_calloc);
	} else {
		printf("Error de memoria.\n");
	}


	int *arr_calloc = (int *)calloc(count, size);

	i = 0;
	if (arr_calloc) {
		printf("Memoria colocada con calloc:\n");
		while (i < count)
		{
			printf("%d ", arr_calloc[i]);
		}
		printf("\n");
		free(arr_calloc);
	} else {
		printf("Error de memoria.\n");
	}

	return (0);
}*/