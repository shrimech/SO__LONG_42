/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 00:12:10 by shrimech          #+#    #+#             */
/*   Updated: 2024/11/06 06:42:42 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	char	*src;
	size_t	reslen;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < (size_t)start)
		return (ft_strdup(""));
	src = (char *)s + start;
	if (ft_strlen(src) < len)
		reslen = ft_strlen(src) + 1;
	else
		reslen = len + 1;
	res = malloc(reslen);
	if (!res)
		return (NULL);
	ft_strlcpy(res, src, reslen);
	return (res);
}
/*#include <stdio.h>

int main()
{
    char *str = "salah eddine";
    char *substr = ft_substr(str, 6, 4);
    printf("%s\n", substr);
    free(substr);
    return 0;
}*/
