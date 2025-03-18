/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 00:06:08 by shrimech          #+#    #+#             */
/*   Updated: 2024/11/05 16:26:16 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	s2len;
	size_t	i;

	s2len = ft_strlen(s2);
	if (s2len == 0)
	{
		return ((char *)s1);
	}
	if (!s1)
	{
		return (0);
	}
	i = 0;
	while (i < n && s1[i] != '\0')
	{
		if (s1[i] == s2[0] && (i + s2len <= n)
			&& ft_strncmp(&s1[i], s2, s2len) == 0)
		{
			return ((char *)&s1[i]);
		}
		i++;
	}
	return (0);
}
/*#include <stdio.h>

int main()
{
    const char *haystack = "Hello, shrimech asjfajhk";
    const char *needle = "sh";
    size_t n = 9;

    char *result = ft_strnstr(haystack, needle, n);
    printf("%s\n", result);
}*/
