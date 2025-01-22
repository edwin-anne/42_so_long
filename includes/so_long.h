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

# define KEY_EXIT		17

typedef struct s_game {
    void    *mlx;
    void    *win;
    void    *img_1;
    void    *img_0;
    void    *img_c;
    void    *img_e;
    void    *img_p;
    int     width;
    int     height;
    char **table;
    char **copied;
    int size_y;
    int size_x;
    int start_y;
    int start_x;
    int items_collected;
    int exit_reached;
    int total_items;
}   t_game;

typedef struct s_count {
    int count_e;
    int count_p;
    int count_c;
}   t_count;

/*#########  GAME  #########*/
int start_game(t_game *game);

/*#########  GAME UTILS  #########*/
t_game *size_window(t_game *game);
t_game *upload_img(t_game *game);
int	render_map(t_game *g);
void	render_map_item(t_game *g, int x, int y);

/*#########  VERIF  #########*/
int character_verif(char *verif, t_count *map_count);
int game_size_verif(char *verif, int back_size);
int map_closed(char *verif, int edge);
int is_start_or_end(int position, int total_lines);
int verif_item_doublon(t_count *map_count);

/*#########  VERIF2  #########*/
int check_map(char *filepath);

/*#########  INSERT  #########*/
t_game	*init_map(char *filepath, t_game *map, int *fd);
void fill_map(int fd, t_game *game);
t_game *insert_map(char *filepath, t_game *game);

/*#########  FLOOD FILL  #########*/
void	flood_fill(t_game *data, int y, int x);
int count_items(t_game *data);
int find_start(t_game *map);
int flood_fill_init(t_game *data);

/*#########  UTILS  #########*/
int count_line(char *filepath);
void print_map(char **map);
t_game *copy_map(t_game *map);
size_t	ft_strlen_map(const char *s);

/*#########  FREE  #########*/
int	free_map(t_game *game);
int	free_exit(t_game *game);
void	free_map_table(t_game *map, int i);

void	ft_player_position(t_game *data);

#endif