/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Edwin ANNE <eanne@student.42lehavre.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:54:30 by Edwin ANNE        #+#    #+#             */
/*   Updated: 2025/01/13 13:54:17 by Edwin ANNE       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

// int check_map(char *filepath)
// {
// 	int			i_read;
// 	int			fd;
// 	char		*read;
// 	map_verif	map;
	

// 	fd = open(filepath, O_RDONLY);
// 	read = get_next_line(fd);
// 	while (read != NULL)
// 	{
// 		printf("%s", read);
// 		free(read);
// 		read = get_next_line(fd);
// 	}
// 	close(fd);

// 	return (0);
// }

int main(int argc, char **argv)
{
	(void)argv;
    t_game  game;

    game.width = 800;
    game.height = 600;
    if (argc != 2)
        return (1);
    // if (check_map(argv[1]) != 0)
    //     return (1);
    if (start_game(&game) != 0)
        return (1);
    mlx_loop(game.mlx);
    return (0);
}