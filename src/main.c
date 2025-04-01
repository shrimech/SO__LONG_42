/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 07:10:31 by shrimech          #+#    #+#             */
/*   Updated: 2025/04/01 00:19:44 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
int ft_exit(t_game *game)
{
	exit((free_game_map(game),free_textures(game),pause_mlx(game),0));
	return 0;
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		game_init(&game);
		if (check_map(av[1], &game) == 0 || map_elements(&game) == 0
			|| elements_count(&game) == 0 
			|| check_oporunity_to_col_exit(&game) == 0)
			return ((/*free_game_map(&game),*/write(1, "ERROR : invalid map\n", 20), 0));
		printf("(%d,%d,%d)\n", game.colect,game.p_x, game.p_y);
		game.mlx = mlx_init();
		game.mlx_win = mlx_new_window(game.mlx,game.width*32,game.high*32,"so_long");
		texture(&game);
		render_map(&game);
		mlx_key_hook(game.mlx_win, key_hook, &game);
		mlx_hook(game.mlx_win, 17, 0, ft_exit, &game);
		mlx_loop(game.mlx);
	}
	else
		write(1, "Error: enter <./so_long> <map.ber>", 34);
}
// okok