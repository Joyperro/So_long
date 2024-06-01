/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclement <dclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:26:53 by dclement          #+#    #+#             */
/*   Updated: 2024/02/23 13:48:13 by dclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	ptr = str;
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = '\0';
	return (str);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	index;

	if (!s)
		return (NULL);
	index = 0;
	if ((unsigned int)ft_strlen(s) <= start)
		return (ft_strdup(""));
	else if (ft_strlen(&s[start]) <= len)
		sub_s = malloc(ft_strlen(&s[start]) + 1);
	else
		sub_s = malloc(len + 1);
	if (!sub_s)
		return (NULL);
	while (index < len && s[start + index] != '\0')
	{
		sub_s[index] = s[start + index];
		index++;
	}
	sub_s[index] = '\0';
	return (sub_s);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	else
		return (NULL);
}

char	*ft_strdup(const char *s1)
{
	int		index;
	char	*ptr;
	char	*result;

	index = 0;
	ptr = malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	result = ptr;
	while (s1[index] != '\0')
	{
		ptr[index] = s1[index];
		index++;
	}
	ptr[index] = '\0';
	return (result);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
