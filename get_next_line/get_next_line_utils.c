/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 04:42:44 by shrimech          #+#    #+#             */
/*   Updated: 2025/03/22 06:45:04 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] )
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		str[j++] = s1[i];
	i = -1;
	while (s2[++i])
		str[j++] = s2[i];
	str[j] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	c = (unsigned char)c;
	i = -1;
	while (s[++i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	size;
	size_t	i;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (start > size)
		len = 0;
	if (size - start < len)
		len = size - start;
	str = malloc((len + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < len)
		str[i] = s[start + i];
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(const char *str)
{
	char	*dup;
	int		i;

	dup = malloc((ft_strlen(str) + 1));
	if (!dup)
		return (0);
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
