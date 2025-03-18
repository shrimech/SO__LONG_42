/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 06:43:06 by shrimech          #+#    #+#             */
/*   Updated: 2024/11/04 06:39:44 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*r;

	r = malloc(count * size);
	if (!r)
		return (NULL);
	ft_bzero(r, size * count);
	return (r);
}
/*#include <stdio.h>
int main() {
    int *array = ft_calloc(5, sizeof(int));

    if (array) {
        for (int i = 0; i < 5; i++) {
            printf("%d ", array[i]); 
        }
    }
}*/
