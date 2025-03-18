/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:43:31 by shrimech          #+#    #+#             */
/*   Updated: 2024/11/02 18:35:10 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
/*void to_upper(unsigned int i, char *c)
{
	*c -= 32;
}
#include <stdio.h>
int main()
{
    char str[] = "elloworld";
    char *str2 = str;
    ft_striteri(str, to_upper);
    printf("Modified: %s\n", str2);
}*/
