/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 19:31:20 by shrimech          #+#    #+#             */
/*   Updated: 2024/11/01 17:20:13 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		ch;
	const unsigned char	*str;

	ch = (unsigned char)c;
	str = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == ch)
			return ((void *)s + i);
		i++;
	}
	return (0);
}
//
//#include <stdio.h>
//
//int main() {
//    const char *string = "Hello, world!";
//    char ch = 'w';
//    char *result = ft_memchr(string, ch, 3);
//
//    printf("%s\n", result);
//}
