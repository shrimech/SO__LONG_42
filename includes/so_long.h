/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:12:33 by shrimech          #+#    #+#             */
/*   Updated: 2025/03/28 01:42:21 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

#include "/usr/include/minilibx-linux/mlx.h"
#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <stdio.h>


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
	void *mlx;
	void *mlx_win;
	void *img_wall;
	void *img_exit;
	void *img_empty;
	void *img_player;
	void *img_collectib;
}			t_game;

//parcing et validation de map
int	elements_count(t_game *game);
int	map_elements(t_game *game);
size_t	gt_strlen(const char *str);
void	hight_map(t_game *game, char *filename);
int	check_map(char *av, t_game *game);
void	find_player_pos(t_game *game);
void	flood_fill(char **map, int x, int y,int i,int j);
char	**duplicate_map(t_game *game);
int	check_oporunity_to_col_exit(t_game *game);
void	game_init(t_game *game);
//window and rendring map
void	render_map(t_game *game);
void	texture(t_game *game);
int	key_hook(int key, t_game *game);


#endif

