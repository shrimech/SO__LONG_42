/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leak_tzb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 00:56:33 by shrimech          #+#    #+#             */
/*   Updated: 2025/03/30 01:09:20 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void free_map(char **map)
{
    int i = 0;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

void free_game_map(t_game *game)
{
    if (!game->map) return;
    for (int i = 0; i < game->high; i++)
        free(game->map[i]);
    free(game->map);
}

void free_textures(t_game *game)
{
    if (game->img_wall) mlx_destroy_image(game->mlx, game->img_wall);
    if (game->img_player) mlx_destroy_image(game->mlx, game->img_player);
    if (game->img_collectib) mlx_destroy_image(game->mlx, game->img_collectib);
    if (game->img_exit) mlx_destroy_image(game->mlx, game->img_exit);
    if (game->img_empty) mlx_destroy_image(game->mlx, game->img_empty);
}