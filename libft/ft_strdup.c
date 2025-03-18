/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 05:16:51 by shrimech          #+#    #+#             */
/*   Updated: 2024/10/31 22:59:02 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*static size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (src[i] && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}
*/
#include"libft.h"
#include <stddef.h>

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	len;

	len = ft_strlen(s1) + 1;
	s2 = malloc(len);
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s1, len);
	return (s2);
}
/*#include <stdio.h>

int main() {
    const char *original = "lk7al simo";
    char *duplicate = ft_strdup(original);

    if (duplicate) {
        printf("Original: %s\n", original);
        printf("Duplicate: %s\n", duplicate);
        free(duplicate);
    } else {
        printf("Failed to duplicate string.\n");
    }

    return 0;
}*/
