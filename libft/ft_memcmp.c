/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:16:19 by shrimech          #+#    #+#             */
/*   Updated: 2024/11/04 06:51:26 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	if (n == 0)
		return (0);
	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	i = 0;
	while ((i < n - 1) && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}
/*#include <stdio.h>

int main() {
    char arr1[] = "Hello";
    char arr2[] = "Hello, World!";

    int result = ft_memcmp(arr1, arr2, 5);
    printf("%d",result);
}
*/
