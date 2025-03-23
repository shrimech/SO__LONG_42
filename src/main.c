/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 07:10:31 by shrimech          #+#    #+#             */
/*   Updated: 2025/03/23 08:14:13 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"
#include <unistd.h>

typedef struct s_game
{
	int		width;
	int		high;
	char	**map;
	int		colect;
	int		exit;
	int		player;
	int		p_x;
	int		p_y;
}			t_game;

void	find_player_pos(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	game->p_x = 0;
	game->p_y = 0;
	while (x < game->high)
	{
		y = 0;
		while (y < game->width)
		{
			if (game->map[x][y] == 'P')
			{
				game->p_y = y;
				game->p_x = x;
				return ;
			}
			y++;
		}
		x++;
	}
}

void	flood_fill(char **map, int x, int y)
{
	if (map[x][y] == '1' || map[x][y] == 'X')
		return ;
	map[x][y] = 'X';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

char	**duplicate_map(t_game *game)
{
	int		i;
	char	**copy;

	i = 0;
	copy = malloc(sizeof(char *) * (game->width + 1));
	if (!copy)
		return (NULL);
	while (game->map[i])
	{
		copy[i] = ft_strdup(game->map[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

int	check_oporunity_to_C_E(t_game *game)
{
	int		i;
	int		j;
	int		c;
	char	**coppy;

	i = 0;
	c = 0;
	find_player_pos(game);
	coppy = duplicate_map(game);
	flood_fill(coppy, game->p_x, game->p_y);
	while (i < game->high)
	{
		j = 0;
		while (j < game->width)
		{
			if (coppy[i][j] == 'C' || coppy[i][j] == 'E')
				c++;
			j++;
		}
		i++;
	}
	if (c != 0)
		return (0);
	return (1);
}

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
	j = 0;
	while ((game->map[0][j] != '\0' && game->map[0][j] != '\n')
		|| (game->map[game->high - 1][j] != '\0' && game->map[game->high
			- 1][j] != '\n'))
	{
		if (game->map[0][j] != '1' || game->map[game->high - 1][j] != '1')
			return (0);
		j++;
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

void  hight_map(t_game *game, char *filename)
{
	int fd;
	char *line;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while(line)
	{
		game->high++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

#include <stdio.h>
int	check_map(char *av, t_game *game)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(av, O_RDONLY);
	// game->map = malloc(countnewline(fd));
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
void	game_init(t_game *game)
{
	game->colect = 0;
	game->exit = 0;
	game->player = 0;
	game->high = 0;
    game->map = NULL;
}
// void	free_map(t_game *game)
// {
// 	int	i;

// 	if (!game->map)
// 		return ;
// 	i = 0;
// 	while (game->map[i])
// 	{
// 		free(game->map[i]);
// 		game->map[i] = NULL;
// 		i++;
// 	}
//     free(game->map[i]);
// }

#include <stdio.h>

int	main(int ac, char **av)
{
	t_game game;
	int i;

	i = 0;
	if (ac == 2)
	{

		game_init(&game);
		if (check_map(av[1], &game) == 0 || map_elements(&game) == 0
			|| elements_count(&game) == 0 || check_oporunity_to_C_E(&game) == 0)
			return (write(1, "ERROR : invalid map\n", 20), 0);
		printf("(%d,%d)\n", game.p_x, game.p_y);
	}
	else
		write(1, "Error: enter <./so_long> <map.ber>", 34);
}
// okok