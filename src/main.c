/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 07:10:31 by shrimech          #+#    #+#             */
/*   Updated: 2025/03/22 09:15:34 by shrimech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
#include <unistd.h>

typedef struct s_game
{
    int width;
    int high;
    char **map;
    int colect;
    int exit;
    int player;
}t_game;

int elements_count(t_game *game)
{
    int i =0;
    int j;
    while (i < game->high)
    {
        j = 0;
        while (j < game->width)
        {
            if (game->map[i][j] == 'C')
                game->colect++;
            if (game->map[i][j] == 'E')
                game->exit++;
            if (game->map[i][j] == 'P')
                game->player++;
            j++;
        }
        i++;
    }
    if(game->colect < 1 || game->exit != 1 || game->player != 1)
        return(0);
    return (1);
}

int map_elements(t_game *game)
{
    int i = 0;
    int j;
    while (game->map[i] != NULL)
    {
        j = 0; 
        while(game->map[i][j] != '\0' && game->map[i][j] != '\n')
        {
            if (game->map[i][j] == '0' || game->map[i][j] == '1' ||game->map[i][j] == 'P' || game->map[i][j] == 'C' || game->map[i][j] == 'E')
                j++;
            else
                return(0);
        }
        i++;
    }
    j = 0;
    while((game->map[0][j] != '\0' && game->map[0][j] != '\n') || (game->map[game->high - 1][j] != '\0' && game->map[game->high - 1][j] != '\n'))
    {
        if (game->map[0][j] != '1' || game->map[game->high - 1][j] != '1')
            return(0);
        j++;
    }
    return(1);
}

size_t	gt_strlen(const char *str)
{
	size_t	i;

    if (str == NULL)
        return 0;
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int check_map(char *av, t_game *game)
{
    int fd;
    int i = 0;
    fd = open(av , O_RDONLY);
    //game->map = malloc(countnewline(fd))
    char *line = get_next_line(fd);
    game->width = gt_strlen(line);
    while(line)
    {
        game->map[i] = malloc(ft_strlen(line));
        game->map[i]=line;
        if(gt_strlen(line) != game->width || game->map[i][0] != '1' || game->map[i][gt_strlen(line) - 1] != '1')
            return(0);
        line = get_next_line(fd);
        i++;
    }
    game->map[i] = NULL;
    game->high = i;
    close(fd);
    return(1);
}
void game_init(t_game *game)
{
    game->colect = 0;
    game->exit = 0;
    game->player = 0;
}

#include<stdio.h>
int main(int ac,char **av)
{
    t_game *game;
    int i;

    i = 0;
    if (ac == 2)
    {
        game_init(game);
        if (check_map(av[1],game) == 0 || map_elements(game) == 0 || elements_count(game) == 0)
            return(write(1,"ERROR : invalid map\n",20),0);
        printf("%d\n",game->high);
    }
    else
        write(1,"Error: enter <./so_long> <map.ber>",34);
}