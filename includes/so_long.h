/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:12:33 by shrimech          #+#    #+#             */
/*   Updated: 2025/04/02 10:38:15 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "/usr/include/minilibx-linux/minilibx-linux/mlx.h"
#include "../ft_printf/ft_printf.h"
# include <unistd.h>

typedef struct s_game
{
	size_t		width;
	size_t		high;
	char	**map;
	int		colect;
	int		exit;
	int		player;
	int		p_x;
	int		p_y;
	int		exit_x;
	int		exit_y;
	void	*mlx;
	void	*mlx_win;
	void	*img_wall;
	void	*img_exit;
	void	*img_empty;
	void	*img_player;
	void	*img_collectib;
	int		count_moves;
}			t_game;

// parcing et validation de map
int			elements_count(t_game *game);
int			map_elements(t_game *game);
size_t		gt_strlen(const char *str);
void		hight_map(t_game *game, char *filename);
int			check_map(char *av, t_game *game);
void		find_player_pos(t_game *game);
void		flood_fill(char **map, int x, int y, t_game *game);
char		**duplicate_map(t_game *game);
int			check_oporunity_to_col_exit(t_game *game);
void		game_init(t_game *game);
// window and rendring map
void		render_map(t_game *game);
void		texture(t_game *game);
// move player
int			key_hook(int key, t_game *game);
void		go_right(t_game *game);
void		go_left(t_game *game);
void		go_up(t_game *game);
void		go_down(t_game *game);
//bad trip with leaks
void free_map(char **map);
void free_game_map(t_game *game);
void free_textures(t_game *game);
void pause_mlx(t_game *game);
void free_if_i(t_game *game, int i);

#endif
