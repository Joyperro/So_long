/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:00:00 by dclement          #+#    #+#             */
/*   Updated: 2024/01/25 16:33:18 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst && (*del))
	{
		(*del)(lst->content);
		free(lst);
	}
	else
		lst = NULL;
}
/*
void	del(void *ptr)
{
	free(ptr);
}
int main()
{
	t_list	*new;
	int	*n;

	n = malloc(sizeof(int));
	*n = 6;
	if (!n)
		return (1);
	new = ft_lstnew(n);
	printf("Contenido antes de del: %d\n", *((int *)new->content));
	ft_lstdelone(new, del);
	return (0);
}*/