/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:14:41 by dclement          #+#    #+#             */
/*   Updated: 2024/01/25 16:33:02 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;

	if (!lst || !(*del))
		lst = NULL;
	else
	{
		while (*lst)
		{
			aux = (*lst)->next;
			(*del)((*lst)->content);
			free(*lst);
			*lst = aux;
		}
		free (*lst);
		*lst = NULL;
	}
}
