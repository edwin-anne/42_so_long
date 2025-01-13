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

typedef struct map_verif
{
	int	size_x;
	int	size_y;
}	map_verif;

typedef struct s_game {
    void    *mlx;
    void    *win;
    int     width;
    int     height;
}   t_game;

int start_game(t_game *game);
int handle_mouse(int button, int x, int y);

#endif