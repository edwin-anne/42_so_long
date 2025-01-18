/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Edwin ANNE <eanne@student.42lehavre.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   */
/*   Created: 2025/01/11 16:58:10 by Edwin ANNE        #+#    #+#             */
/*   Updated: 2025/01/11 21:36:34 by Edwin ANNE       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "libft.h"
# include "get_next_line.h"

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_map {
    char **table;
    char **copied;
    int size_y;
    int size_x;
    int start_y;
    int start_x;
    int items_collected;
    int exit_reached;
    int total_items;
}   t_map;

typedef struct s_game {
    void    *mlx;
    void    *win;
    int     width;
    int     height;
}   t_game;

int start_game(t_game *game);
int handle_mouse(int button, int x, int y, void *param);

/*#########  VERIF  #########*/
int character_verif(char *verif);
int game_size_verif(char *verif, int back_size);
int map_closed(char *verif, int edge);
int is_start_or_end(int position, int total_lines);

/*#########  INSERT  #########*/
t_map init_map(char *filepath, t_map map, int *fd);
void fill_map(int fd, t_map map);
t_map insert_map(char *filepath, t_map map);

/*#########  FLOOD FILL  #########*/
void	flood_fill(t_map *data, int y, int x);
int count_items(t_map *data);
int find_start(t_map *map);
int flood_fill_init(t_map *data);

/*#########  UTILS  #########*/
int count_line(char *filepath);
void print_map(char **map);
t_map copy_map(t_map map);

void	ft_player_position(t_map *data);

#endif