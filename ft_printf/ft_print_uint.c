/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:41:35 by dclement          #+#    #+#             */
/*   Updated: 2024/02/20 17:02:55 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putunbr(unsigned int n)
{
	if (n < 10)
		ft_putchar_fd(n + '0', 1);
	else
	{
		ft_print_uint(n / 10);
		ft_print_uint(n % 10);
	}
}

int	ft_print_uint(unsigned int n)
{
	ft_putunbr(n);
	return (ft_num_length(n));
}
