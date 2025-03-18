/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:34:52 by shrimech          #+#    #+#             */
/*   Updated: 2024/11/04 01:22:13 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

static size_t	num_len(long num)
{
	size_t	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		len++;
		num = -num;
	}
	while (num >= 1)
	{
		len++;
		num /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	a;
	char	*str;
	size_t	len;

	a = n;
	len = num_len(a);
	str = ft_calloc(len + 1, 1);
	if (!str)
		return (NULL);
	if (a < 0)
	{
		str[0] = '-';
		a = -a;
	}
	len--;
	while (len)
	{
		str[len] = (a % 10) + '0';
		a /= 10;
		len--;
	}
	if (str[0] != '-')
		str[0] = a % 10 + '0';
	return (str);
}
/*
int main(void) 
{
	
        printf("%s\n", result);
}*/
