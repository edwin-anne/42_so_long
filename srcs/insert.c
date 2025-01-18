/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Edwin ANNE <eanne@student.42lehavre.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:10:47 by Edwin ANNE        #+#    #+#             */
/*   Updated: 2025/01/16 23:04:55 by Edwin ANNE       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map init_map(char *filepath, t_map map, int *fd)
{
    char *read;

    map.size_y = count_line(filepath);
    *fd = open(filepath, O_RDONLY);
    if (*fd < 0)
        return (map);
    read = get_next_line(*fd);
    if (!read)
        return (map);
    map.size_x = ft_strlen(read) - 1;
    map.table = (char **)malloc(sizeof(char *) * (map.size_y + 1));
    if (!map.table)
    {
        free(read);
        close(*fd);
        return (map);
    }
    map.table[0] = (char *)malloc(sizeof(char) * (map.size_x + 1));
    if (!map.table[0])
    {
        free(read);
        return (map);
    }
    ft_strlcpy(map.table[0], read, map.size_x + 1);
    free(read);
    return (map);
}

void fill_map(int fd, t_map map)
{
    char *read;
    int i, y;

    y = 1;
    read = get_next_line(fd);
    while (read != NULL && y < map.size_y)
    {
        map.table[y] = (char *)malloc(sizeof(char) * (map.size_x + 1));
        if (!map.table[y])
        {
            free(read);
            return;
        }
        i = 0;
        while (read[i] && read[i] != '\n')
        {
            map.table[y][i] = read[i];
            i++;
        }
        map.table[y][i] = '\0';
        free(read);
        read = get_next_line(fd);
        y++;
    }
    map.table[y] = NULL;
}

t_map insert_map(char *filepath, t_map map)
{
    int fd;

    map = init_map(filepath, map, &fd);
    if (!map.table)
        return (map);
    fill_map(fd, map);
    close(fd);
    return (map);
}
