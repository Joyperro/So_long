/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:43:51 by dclement          #+#    #+#             */
/*   Updated: 2024/01/25 16:25:41 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*sub_hay;
	const char	*sub_needle;
	size_t		index;

	if (!haystack && len == 0)
		return (NULL);
	if (*needle == '\0')
		return ((char *)haystack);
	else
	{
		while (*haystack && (len > 0))
		{
			index = 0;
			sub_hay = haystack;
			sub_needle = needle;
			while (*sub_hay++ == *sub_needle++ && index++ < len)
			{
				if (*sub_needle == '\0')
					return ((char *)haystack);
			}
			haystack++;
			len--;
		}
	}
	return (0);
}
/*
int	main(void)
{
	char s1[30] = "aaabcabcd";
	char s2[] = "abcd";
	char *ptr;
	char *ptr2;

	ptr = strnstr(s1, s2, 11);
	ptr2 = ft_strnstr(s1, s2, 11);
	if (ptr == s1 +5 && ptr2 == s1 + 5)
	{
		printf("Mi strnstr:		%s", ptr);
		printf("Strnstr original :	%s\n", ptr);
	}
	else
	{
		printf("Mi strnstr 23:		%s\n", ptr);
		printf("Strnstr original  23:	%s\n", ptr);
	}
	return (0);
}*/