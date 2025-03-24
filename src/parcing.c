/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 07:26:05 by shrimech          #+#    #+#             */
/*   Updated: 2025/03/24 08:43:15 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	elements_count(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->high)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'C')
				game->colect++;
			if (game->map[i][j] == 'E')
				game->exit++;
			if (game->map[i][j] == 'P')
				game->player++;
			j++;
		}
		i++;
	}
	if (game->colect < 1 || game->exit != 1 || game->player != 1)
		return (0);
	return (1);
}

int	map_elements(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0' && game->map[i][j] != '\n')
		{
			if (game->map[i][j] == '0' || game->map[i][j] == '1'
				|| game->map[i][j] == 'P' || game->map[i][j] == 'C'
				|| game->map[i][j] == 'E')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

size_t	gt_strlen(const char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

void	hight_map(t_game *game, char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		game->high++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

int	check_map(char *av, t_game *game)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(av, O_RDONLY);
	game->map = malloc(sizeof(char *) * (game->high + 1));
	line = get_next_line(fd);
	if (!line)
		return (0);
	game->width = gt_strlen(line);
	while (line)
	{
		game->map[i] = ft_strdup(line);
		if (gt_strlen(line) != game->width || game->map[i][0] != '1'
			|| game->map[i][gt_strlen(line) - 1] != '1')
			return (0);
		line = get_next_line(fd);
		i++;
	}
	game->map[i] = NULL;
	game->high = i;
	close(fd);
	return (1);
}
