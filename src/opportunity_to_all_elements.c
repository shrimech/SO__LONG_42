/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opportunity_to_all_elements.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 07:20:53 by shrimech          #+#    #+#             */
/*   Updated: 2025/03/30 01:16:34 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	find_player_pos(t_game *game)
{
	size_t	x;
	size_t	y;

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

void	flood_fill(char **map, int x, int y, int i, int j)
{
	if (x < 0 || x >= j || y < 0 || y >= i || map[x][y] == '1'
		|| map[x][y] == 'X')
		return ;
	map[x][y] = 'X';
	flood_fill(map, x + 1, y, i, j);
	flood_fill(map, x - 1, y, i, j);
	flood_fill(map, x, y + 1, i, j);
	flood_fill(map, x, y - 1, i, j);
}

char	**duplicate_map(t_game *game)
{
	int		i;
	char	**copy;

	i = 0;
	copy = malloc(sizeof(char *) * (game->high + 1));
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

int	check_oporunity_to_col_exit(t_game *game)
{
	size_t	i;
	size_t	j;
	int		c;
	char	**coppy;

	i = 0;
	c = 0;
	find_player_pos(game);
	coppy = duplicate_map(game);
	flood_fill(coppy, game->p_x, game->p_y, game->width, game->high);
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
	free_map(coppy);
	if (c != 0)
		return (0);
	return (1);
}

void	game_init(t_game *game)
{
	game->colect = 0;
	game->exit = 0;
	game->player = 0;
	game->high = 0;
	game->exit_x = 0;
	game->exit_y = 0;
	game->count_moves = 0;
	game->map = NULL;
}