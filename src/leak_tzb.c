/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leak_tzb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 00:56:33 by shrimech          #+#    #+#             */
/*   Updated: 2025/04/02 08:04:48 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	pause_mlx(t_game *game)
{
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_game_map(t_game *game)
{
	size_t	i;

	i = 0;
	if (!game->map)
		return ;
	while (i < game->high)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	free_textures(t_game *game)
{
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_collectib)
		mlx_destroy_image(game->mlx, game->img_collectib);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_empty)
		mlx_destroy_image(game->mlx, game->img_empty);
}

void	free_if_i(t_game *game, int i)
{
	while (i >= 0)
	{
		free(game->map[i]);
		i--;
	}
	free(game->map);
}
