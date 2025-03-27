/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:20:29 by shrimech          #+#    #+#             */
/*   Updated: 2025/03/27 18:35:29 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


void	init_cepew(t_game *game)
{
	game->img_wall = NULL;
	game->img_player = NULL;
	game->img_collectib = NULL;
	game->img_exit = NULL;
	game->img_empty = NULL;
}

void	texture(t_game *game)
{
	int	a;

	a = 32;
	init_cepew(game);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "../texture/wall.xpm", &a, &a);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "../texture/player.xpm", &a,
			&a);
	game->img_collectib = mlx_xpm_file_to_image(game->mlx, "../texture/collectib.xpm",
			&a, &a);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "../texture/exit.xpm", &a, &a);
	game->img_empty = mlx_xpm_file_to_image(game->mlx, "../texture/empty.xpm", &a, &a);
	if (!game->img_wall || !game->img_player || !game->img_collectib || !game->img_exit
		|| !game->img_empty)
		(write(2, "Error: Failed to load textures\n", 30));
}

void	render_map(t_game *game)
{
	int i;
	int j;
	
	i = 0;
	while(game->map[i])
	{
		j = 0;
		while(game->map[i][j])
		{
			if (game->map[i][j] = '0')
				mlx_put_image_to_window(game->mlx,game->mlx_win,game->img_empty, i*32,j*32);
			if (game->map[i][j] = '1')
				mlx_put_image_to_window(game->mlx,game->mlx_win,game->img_wall, i*32,j*32);
			if (game->map[i][j] = 'P')
				mlx_put_image_to_window(game->mlx,game->mlx_win,game->img_player, i*32,j*32);
			if (game->map[i][j] = 'E')
				mlx_put_image_to_window(game->mlx,game->mlx_win,game->img_exit, i*32,j*32);
			if (game->map[i][j] = 'C')
				mlx_put_image_to_window(game->mlx,game->mlx_win,game->img_collectib, i*32,j*32);
			j++;
		}
		i++;
	}
}