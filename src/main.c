/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 07:10:31 by shrimech          #+#    #+#             */
/*   Updated: 2025/03/24 08:24:40 by shrimech         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_game	game;
	int		i;

	i = 0;
	if (ac == 2)
	{
		game_init(&game);
		if (check_map(av[1], &game) == 0 || map_elements(&game) == 0
			|| elements_count(&game) == 0 
			|| check_oporunity_to_col_exit(&game) == 0)
			return (write(1, "ERROR : invalid map\n", 20), 0);
		printf("(%d,%d)\n", game.p_x, game.p_y);
	}
	else
		write(1, "Error: enter <./so_long> <map.ber>", 34);
}
// okok