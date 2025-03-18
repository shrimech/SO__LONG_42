/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:12:04 by shrimech          #+#    #+#             */
/*   Updated: 2024/11/04 01:23:54 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dp;
	const char	*sp;

	dp = (char *)dst;
	sp = (const char *)src;
	if (!dp && !sp && n == 0)
		return (dst);
	while (n--)
	{
		*dp++ = *sp++;
	}
	return (dst);
}
