/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:24:20 by shrimech          #+#    #+#             */
/*   Updated: 2024/11/01 11:30:14 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	if (!s || !f)
		return (ft_strdup(""));
	else if (!f)
		return (ft_strdup(s));
	str = ft_strdup(s);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	return (str);
}
/*
char to_upper(unsigned int i, char c)
{
	c -= 32;
	return(c);
}
#include <stdio.h>
int main()
{
    const char *original = "hello world";
    char *modified = ft_strmapi(original, to_upper);

    if (modified) {
        printf("Original: %s\n", original);
        printf("Modified: %s\n", modified);
        free(modified);
    } else {
        printf("Memory allocation failed!\n");
    }

    return 0;
}*/
