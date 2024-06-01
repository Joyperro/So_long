/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:29:36 by dclement          #+#    #+#             */
/*   Updated: 2024/02/21 12:54:10 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_length(unsigned long hex)
{
	int	count;

	count = 0;
	if (hex == 0)
		count++;
	while (hex > 0)
	{
		hex = hex / 16;
		count++;
	}
	return (count);
}

int	ft_print_hex(unsigned long hex, char *base)
{
	if (hex < 16)
	{
		ft_putchar_fd(base[hex], 1);
	}
	else if (hex >= 16)
	{
		ft_print_hex(hex / 16, base);
		ft_print_hex(hex % 16, base);
	}
	return (hex_length(hex));
}
