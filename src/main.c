/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 07:10:31 by shrimech          #+#    #+#             */
/*   Updated: 2025/04/02 10:37:55 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_exit(t_game *game)
{
	exit((free_game_map(game), free_textures(game), pause_mlx(game), 1));
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		if (ft_strlen(av[1]) <= 4 || ft_strncmp(ft_strrchr(av[1], '.'), ".ber", 4) != 0)
			return ((write(2, "Error : file of map chould be <*.ber>", 37), 1));
		game_init(&game);
		if (check_map(av[1], &game) == 0 || map_elements(&game) == 0
			|| elements_count(&game) == 0
			|| check_oporunity_to_col_exit(&game) == 0)
			return ((write(2, "ERROR : invalid map\n", 20), 0));
		game.mlx = mlx_init();
		texture(&game);
		game.mlx_win = mlx_new_window(game.mlx, game.width * 32, game.high * 32,
				"so_long");
		render_map(&game);
		mlx_key_hook(game.mlx_win, key_hook, &game);
		mlx_hook(game.mlx_win, 17, 0, ft_exit, &game);
		mlx_loop(game.mlx);
	}
	else
		return(write(1, "Error: enter <./so_long> <map.ber>", 34), 1);
}
// okok