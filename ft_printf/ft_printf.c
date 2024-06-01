/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:36:00 by dclement          #+#    #+#             */
/*   Updated: 2024/02/26 19:10:01 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_type(va_list args, const char s, int count)
{
	if (s == 'c')
		count += ft_print_char(va_arg(args, int));
	else if (s == 's')
		count += ft_print_str(va_arg(args, char *));
	else if (s == 'p')
	{
		write (1, "0x", 2 * sizeof(char));
		count += 2;
		count += ft_print_hex(va_arg(args, uintptr_t), "0123456789abcdef");
	}
	else if (s == 'd' || s == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (s == 'u')
		count += ft_print_uint(va_arg(args, unsigned long));
	else if (s == 'x')
		count += ft_print_hex(va_arg(args, unsigned int), "0123456789abcdef");
	else if (s == 'X')
		count += ft_print_hex(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (s == '%')
	{
		write(1, "%", sizeof(char));
		count += 1;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	if (!format)
		return (-1);
	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			count = ft_check_type(args, format[i + 1], count);
			i++;
		}
		else if (format[i] != '%')
		{
			write (1, &format[i], sizeof(char));
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

// int main()
// {
// 	int	count;
// 	int	count2;
// 	int	*ptr;

// 	ptr = malloc(5 * sizeof(int));
// 	count = ft_printf("Esto es una prueba1: %s \n", "hola");
// 	count2 = printf("Esto es una prueba2: %s \n", "hola");
// 	printf("%d\n", count);
// 	printf("%d", count2);
// 	free(ptr);
// 	return (0);
// }
