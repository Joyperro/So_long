/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:37:06 by dclement          #+#    #+#             */
/*   Updated: 2024/01/24 19:32:07 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*aux_lst;
	t_list	*contents;
	void	*ptr;

	if (!lst || !(*f) || !(*del))
		return (NULL);
	aux_lst = NULL;
	while (lst)
	{
		ptr = (*f)(lst->content);
		contents = ft_lstnew(ptr);
		if (!contents)
		{
			(*del)(ptr);
			ft_lstclear(&aux_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&aux_lst, contents);
		lst = lst->next;
	}
	return (aux_lst);
}
/*
void	*f(void *ptr)
{
	int	*n = malloc(sizeof(int));
	if (n)
		*n = *((int*)ptr) + 1;
	return (n);
}
void	del(void *ptr)
{
	free(ptr);
}
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
int main()
{
	t_list *new_list;
	int n = 2;
	int m = 9;
	t_list	*second;

	new_list = ft_lstnew(NULL);
	new_list->content = &n;
	new_list->next = ft_lstnew(&m);
	second = ft_lstmap(&(*new_list), &(*f), &del);
	while (second)
	{
		printf("contenido: %d", *((int *)second->content));
		second = second->next;
		free(second);
	}
	return (0);
}*/
