/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:50:20 by shrimech          #+#    #+#             */
/*   Updated: 2025/03/30 06:28:28 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*temp;
	size_t		start_next;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (temp == NULL)
		temp = ft_strdup("");
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	temp = the_line(fd, buffer, temp);
	free(buffer);
	if (!temp)
		return (NULL);
	line = extract_line(temp, &start_next);
	if (!line && !temp)
		return (NULL);
	temp = keep_rest(temp, start_next);
	return (line);
}

// #include <stdio.h>
// int main()
// {
//  	char *str;
//   	int fd = open("s", O_RDONLY);
//  	// int fd1 = open("h", O_RDONLY);
//  	// printf("%s",get_next_line(fd));
//  	// printf("%s",get_next_line(fd1));
//  	// printf("%s",get_next_line(fd));
//  	// printf("%s",get_next_line(fd1));
//  	// printf("%s",get_next_line(fd));
//  	// printf("%d\n",fd);
//  	while ((str = get_next_line(fd)) != NULL){
//  		printf("%s",str);
//  		free(str);
//  	}
//  }