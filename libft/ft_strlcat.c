/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 22:35:13 by shrimech          #+#    #+#             */
/*   Updated: 2024/11/03 21:31:42 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s;
	size_t	di;
	size_t	si;

	si = ft_strlen(src);
	if (size == 0)
		return (si);
	di = ft_strlen(dst);
	if (size <= di)
		return (size + si);
	s = 0;
	while (src[s] && s + di + 1 < size)
	{
		dst[di + s] = src[s];
		s++;
	}
	dst[di + s] = '\0';
	return (di + si);
}
