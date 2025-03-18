/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:28:19 by shrimech          #+#    #+#             */
/*   Updated: 2024/11/03 22:39:09 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	len;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	j = 0;
	while (s1[j])
	{
		s[j] = s1[j];
		j++;
	}
	i = 0;
	while (s2[i])
	{
		s[j + i] = s2[i];
		i++;
	}
	s[i + j] = '\0';
	return (s);
}
/*#include <stdio.h>

int main()
{
	char a[] = "salah ";
	char b[] = "eddine";
	char *c = ft_strjoin(a, b);
	printf("%s\n", c);
}*/
