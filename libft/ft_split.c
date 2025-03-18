/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 06:43:07 by shrimech          #+#    #+#             */
/*   Updated: 2024/11/14 08:15:34 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static char	**freemem(char **lst, size_t i)
{
	while (i--)
		free(lst[i]);
	free(lst);
	return (NULL);
}

static size_t	ft_countword(char const *s, char c)
{
	size_t	cword;

	if (!*s)
		return (0);
	cword = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			cword++;
		while (*s && *s != c)
			s++;
	}
	return (cword);
}

char	**ft_split(char const *s, char c)
{
	char	**lst;
	size_t	word_len;
	int		i;

	if (!s)
		return (0);
	lst = malloc((ft_countword(s, c) + 1) * 8);
	if (!lst)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!ft_strchr(s, c))
			word_len = ft_strlen(s);
		else
			word_len = ft_strlen(s) - ft_strlen(ft_strchr(s, c));
		if (word_len != 0)
			lst[i++] = ft_substr(s, 0, word_len);
		if (!lst)
			return (freemem(lst, i));
		s += word_len;
	}
	return (lst[i] = NULL, lst);
}
/*
#include <stdio.h>
int main()
{
	char a[] = "...........";
	char b = '.';
	int i;
	char **c = ft_split(a, b);
	i = 0;
	while (c[i] != NULL) 
	{
        	printf("Word %u: %s\n", i + 1, c[i]); 
		i++;
	}
	printf("%s \n", c[i]);
}*/
