/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:31:15 by dclement          #+#    #+#             */
/*   Updated: 2024/01/24 20:24:35 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*aux;

	if (!lst)
		lst = NULL;
	else
	{
		aux = lst;
		while (aux->next)
		{
			(*f)(aux->content);
			aux = aux->next;
		}
		(*f)(aux->content);
	}
}
/*
void	change_char(void *ptr)
{
	*(char *)ptr = *(char *)ptr + 1;
}
int main()
{
	t_list	*new;
	t_list	*temp;
	char	*s;
	char	*s1;

	s = malloc(5 * sizeof(char));
	s1 = malloc(6 * sizeof(char));
	if (!s || !s1)
		return (1);
	s = ft_strdup("hola");
	s1 = ft_strdup("mundo");
	new = ft_lstnew(s);
	new->next = ft_lstnew(s1);
	ft_lstiter(new, change_char);
	while (new)
	{
		printf("contenido: %s", ((char*)new->content));
		temp = new;
		new = new->next;
		free(temp->content);
		free(temp);
	}
	free(new);
	return(0);
}*/
