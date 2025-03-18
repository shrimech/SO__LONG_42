/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:01:17 by shrimech          #+#    #+#             */
/*   Updated: 2024/11/04 01:26:32 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int				i;
	unsigned char	ch;

	ch = (unsigned char)c;
	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == ch)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == ch)
	{
		return ((char *)&str[i]);
	}	
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int main() {
   const char *string = "Hello, world!";
//    char ch = 'w';
   char *result = ft_strchr(string, '\0');

   printf("%s \n", result - 1);
}*/
