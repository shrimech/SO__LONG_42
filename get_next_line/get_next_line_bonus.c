/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 23:43:58 by shrimech          #+#    #+#             */
/*   Updated: 2024/12/29 02:50:19 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*keep_rest(char *temp, int start)
{
	char	*rest;
	int		len;

	len = ft_strlen(temp) - start;
	if (len <= 0)
	{
		free(temp);
		return (NULL);
	}
	rest = ft_substr(temp, start, len);
	free(temp);
	return (rest);
}

static char	*extract_line(char *temp, size_t *start_next)
{
	char	*line;
	int		i;

	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (temp[i] == '\n')
		*start_next = i + 1;
	else
	{
		*start_next = i;
		if (i == 0 && temp[i] == '\0')
			return (NULL);
	}
	line = ft_substr(temp, 0, *start_next);
	return (line);
}

static char	*the_line(int fd, char *buffer, char *temp)
{
	ssize_t			read_bytes;
	char			*new_temp;

	while (!ft_strchr(temp, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == 0 && temp[0] == '\0')
		{
			free(temp);
			return (NULL);
		}
		if (read_bytes <= 0)
			return (temp);
		buffer[read_bytes] = '\0';
		new_temp = ft_strjoin(temp, buffer);
		free(temp);
		temp = new_temp;
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*temp[1024];
	size_t		start_next;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (temp[fd] == NULL)
		temp[fd] = ft_strdup("");
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	temp[fd] = the_line(fd, buffer, temp[fd]);
	free(buffer);
	if (!temp[fd])
		return (NULL);
	line = extract_line(temp[fd], &start_next);
	if (!line && !temp[fd])
		return (NULL);
	temp[fd] = keep_rest(temp[fd], start_next);
	return (line);
}
//khesni n7aydha
// #include <stdio.h>
// int main()
// {
// 	char *str;
// 	int fd = open("s", O_RDONLY);
// 	int fd1 = open("h", O_RDONLY);
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd1));
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd1));
// 	printf("%s",get_next_line(fd));
// 	// printf("%d\n",fd);
// 	// while ((str = get_next_line(fd)) != NULL){
// 	// 	printf("%s",str);
// 	// 	free(str);
// 	// }
// }
