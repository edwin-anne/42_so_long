/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Edwin ANNE <eanne@student.42lehavre.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:54:30 by Edwin ANNE        #+#    #+#             */
/*   Updated: 2025/01/19 20:17:14 by Edwin ANNE       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_map(char *filepath)
{
	int			i_read;
	int			fd;
    int         size_verif;
	char		*read;
    int         lines_count;
    t_item_counter *map_count;
	
    i_read = 0;
    lines_count = count_line(filepath);
	fd = open(filepath, O_RDONLY);
	read = get_next_line(fd);
    size_verif = -1;
    map_count = malloc(sizeof(t_item_counter));
    map_count->count_e = 0;
    map_count->count_p = 0;
    map_count->count_c = 0;
	while (read != NULL)
	{
        size_verif = game_size_verif(read, size_verif);
        if (!character_verif(read, map_count) || size_verif == -1)
            return (0);
        if (!map_closed(read, is_start_or_end(i_read, lines_count)))
            return (0);
		read = get_next_line(fd);
        i_read++;
	}
    free(read);
	close(fd);
    if (!verif_item_doublon(map_count))
            return (0);
    else
	    return (1);
}

int main(int argc, char **argv)
{
    t_map map;
    t_game *game;
    
    if (argc != 2)
        return (1);
    if (!check_map(argv[1]))
    {
        printf("error\n");
        return (1);
    }
    game = malloc(sizeof(t_game));
    if (!game)
        return (1);
    ft_memset(game, 0, sizeof(t_game));
    ft_memset(&map, 0, sizeof(t_map));
    map = insert_map(argv[1], map);
    map = copy_map(map);
    
    if (!map.table || !map.copied)
    {
        free(game);
        return (1);
    }

    if (start_game(game, map))
    {
        free(game);
        return (1);
    }
    
    return (0);
}