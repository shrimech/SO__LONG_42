/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrimech <shrimech@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 07:10:31 by shrimech          #+#    #+#             */
/*   Updated: 2025/03/21 23:01:06 by shrimech         ###   ########.fr       */
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
}t_game;

int countnewline(int fd)
{
    
}

int check_map(char *av, t_game *game)
{
    int fd;
    int i = 0;
    fd = open(av , O_RDONLY);
    //game->map = malloc(countnewline(fd))
    char *line = get_next_line(fd);
    game->width = ft_strlen(line);
    while(line)
    {
        game->map[i] = malloc(ft_strlen(line)+12);
        game->map[i]=line;
        line = get_next_line(fd);
        if(ft_strlen(line) != game->width || game->map[i][0] != '1')
            return(0);
        i++;
    }
    close(fd);
    return(1);
}

#include<stdio.h>
int main(int ac,char **av)
{
    t_game *game;
    int i;

    i = 0;
    if (ac == 2)
    {
        if (check_map(av[1],game) == 0)
            return(write(1,"ERROR : invalid map\n",20),0);
        printf("%s\n",game->map[5]);
    }
    else
        write(1,"Error: enter <./so_long> <mab.ber>",34);
}