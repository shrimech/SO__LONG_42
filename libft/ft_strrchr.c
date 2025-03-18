/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:32:56 by shrimech          #+#    #+#             */
/*   Updated: 2024/11/01 17:18:33 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			offset;
	char			*p;
	unsigned char	ch;

	ch = c;
	offset = ft_strlen(s);
	p = (char *)s + offset;
	if (ch == '\0')
		return (p++);
	while (p >= s)
	{
		if (*p == ch)
			return (p);
		p--;
	}
	p = NULL;
	return (p);
}
