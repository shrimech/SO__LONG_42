/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:51:35 by shrimech          #+#    #+#             */
/*   Updated: 2025/03/18 07:21:44 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char *) src;
	d = (unsigned char *) dest;
	if (d > s)
		while (n--)
			d[n] = s[n];
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
/*
//#include <stdio.h>
#include <string.h>
int main() {
    char source[] = "Hello, World!";
    char destination[50];

    ft_memmove(destination, source, strlen(source) + 1);
    printf("Source: %s\n", source);
    printf("Destination: %s\n", destination);

    char overlap[] = "Hello, World!";
    printf("Before overlapping move: %s\n", overlap);
    ft_memmove(overlap + 7, overlap, 6);
    printf("After overlapping move: %s\n", overlap);

    return 0;
}*/
