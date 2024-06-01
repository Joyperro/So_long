/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:53:14 by dclement          #+#    #+#             */
/*   Updated: 2024/01/25 13:09:19 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*head;

	head = malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	head->content = content;
	head->next = NULL;
	return (head);
}
/*
int main()
{
	char	s1[] = "Hola";
	char	s2[] = "Mundo";
	t_list	*new;

	new = ft_lstnew(s1);
	printf("Contenido: %s\n", new->content);
	free(new);
	new = ft_lstnew(s2);
	printf("Contenido: %s\n", new->content);
	free(new);
	return (0);
}*/
