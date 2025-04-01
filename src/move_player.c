/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:02:54 by shrimech          #+#    #+#             */
/*   Updated: 2025/04/01 00:26:19 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	go_up(t_game *game)
{
	if (game->map[game->p_x - 1][game->p_y] == '1')
		return ;
	if (game->map[game->p_x - 1][game->p_y] == 'E')
	{
		if (game->colect == 0 && game->count_moves++)
		{
			printf("\n*********************************\n");
			printf("*        CONGRATULATIONS        *\n");
			printf("*           YOU WON in %d!      *\n", game->count_moves);
			printf("*********************************\n\n");
			exit((free_game_map(game), free_textures(game), pause_mlx(game),
					0));
		}
		game->exit_x = game->p_x - 1;
		game->exit_y = game->p_y;
	}
	if (game->map[game->exit_x][game->exit_y] == 'P')
		game->map[game->p_x][game->p_y] = 'E';
	else
		game->map[game->p_x][game->p_y] = '0';
	game->p_x--;
	if (game->map[game->p_x][game->p_y] == 'C')
		game->colect--;
	game->map[game->p_x][game->p_y] = 'P';
	game->count_moves++;
}

void	go_left(t_game *game)
{
	if (game->map[game->p_x][game->p_y - 1] == '1')
		return ;
	if (game->map[game->p_x][game->p_y - 1] == 'E')
	{
		if (game->colect == 0 && game->count_moves++)
		{
			printf("\n*********************************\n");
			printf("*        CONGRATULATIONS        *\n");
			printf("*           YOU WON in %d!      *\n", game->count_moves);
			printf("*********************************\n\n");
			exit((free_game_map(game), free_textures(game), pause_mlx(game),
					0));
		}
		game->exit_x = game->p_x;
		game->exit_y = game->p_y - 1;
	}
	if (game->map[game->exit_x][game->exit_y] == 'P')
		game->map[game->p_x][game->p_y] = 'E';
	else
		game->map[game->p_x][game->p_y] = '0';
	game->p_y--;
	if (game->map[game->p_x][game->p_y] == 'C')
		game->colect--;
	game->map[game->p_x][game->p_y] = 'P';
	game->count_moves++;
}

void	go_down(t_game *game)
{
	if (game->map[game->p_x + 1][game->p_y] == '1')
		return ;
	if (game->map[game->p_x + 1][game->p_y] == 'E')
	{
		if (game->colect == 0 && game->count_moves++)
		{
			printf("\n*********************************\n");
			printf("*        CONGRATULATIONS        *\n");
			printf("*           YOU WON in %d!      *\n", game->count_moves);
			printf("*********************************\n\n");
			exit((free_game_map(game), free_textures(game), pause_mlx(game),
					0));
		}
		game->exit_x = game->p_x + 1;
		game->exit_y = game->p_y;
	}
	if (game->map[game->exit_x][game->exit_y] == 'P')
		game->map[game->p_x][game->p_y] = 'E';
	else
		game->map[game->p_x][game->p_y] = '0';
	game->p_x++;
	if (game->map[game->p_x][game->p_y] == 'C')
		game->colect--;
	game->map[game->p_x][game->p_y] = 'P';
	game->count_moves++;
}

void	go_right(t_game *game)
{
	if (game->map[game->p_x][game->p_y + 1] == '1')
		return ;
	if (game->map[game->p_x][game->p_y + 1] == 'E')
	{
		if (game->colect == 0 && game->count_moves++)
		{
			printf("\n*********************************\n");
			printf("*        CONGRATULATIONS        *\n");
			printf("*           YOU WON in %d!      *\n", game->count_moves);
			printf("*********************************\n\n");
			exit((free_game_map(game), free_textures(game), pause_mlx(game),
					0));
		}
		game->exit_x = game->p_x;
		game->exit_y = game->p_y + 1;
	}
	if (game->map[game->exit_x][game->exit_y] == 'P')
		game->map[game->p_x][game->p_y] = 'E';
	else
		game->map[game->p_x][game->p_y] = '0';
	game->p_y++;
	if (game->map[game->p_x][game->p_y] == 'C')
		game->colect--;
	game->map[game->p_x][game->p_y] = 'P';
	game->count_moves++;
}
