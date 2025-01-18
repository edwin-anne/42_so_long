/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Edwin ANNE <eanne@student.42lehavre.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:54:30 by Edwin ANNE        #+#    #+#             */
/*   Updated: 2025/01/16 23:06:01 by Edwin ANNE       ###   ########.fr       */
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
	
    i_read = 0;
    lines_count = count_line(filepath);
	fd = open(filepath, O_RDONLY);
	read = get_next_line(fd);
    size_verif = -1;
	while (read != NULL)
	{
        size_verif = game_size_verif(read, size_verif);
        if (!character_verif(read) || size_verif == -1)
            return (0);
        if (!map_closed(read, is_start_or_end(i_read, lines_count)))
            return (0);
		free(read);
		read = get_next_line(fd);
        i_read++;
	}
	close(fd);
	return (1);
}

int main(int argc, char **argv)
{
    t_map map;
    
    if (argc != 2)
        return (1);
    if (!check_map(argv[1]))
    {
        write(1, "La map n'est pas valide\n", 24);
        return (0);
    }
    
    ft_memset(&map, 0, sizeof(t_map));
    map = insert_map(argv[1], map);
    map = copy_map(map);
    
    if (!map.table || !map.copied)
        return (0);
    // print_map(map.table);
    
    // printf("Taille de la map x=%d y=%d\n", map.size_x, map.size_y);
    printf("Resultat de flood fill -> %d", flood_fill_init(&map));
    // print_map(map.copied);
    // printf("\n");
    // print_map(map.table);
    
    // Libérer la mémoire ici
    return (0);
}