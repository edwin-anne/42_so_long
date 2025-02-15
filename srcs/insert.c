/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanne <eanne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:10:47 by Edwin ANNE        #+#    #+#             */
/*   Updated: 2025/01/29 08:29:38 by eanne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*init_map(char *filepath, t_game *map, int *fd)
{
	char	*read;

	map->size_y = count_line(filepath);
	read = get_next_line(*fd);
	if (!read)
		return (map);
	map->size_x = ft_strlen(read) - 1;
	map->table = (char **)malloc(sizeof(char *) * (map->size_y + 1));
	if (!map->table)
	{
		free(read);
		close(*fd);
		return (map);
	}
	map->table[0] = (char *)malloc(sizeof(char) * (map->size_x + 1));
	if (!map->table[0])
	{
		free(read);
		return (map);
	}
	ft_strlcpy(map->table[0], read, map->size_x + 1);
	free(read);
	return (map);
}

void	fill_map(int fd, t_game *map)
{
	char	*read;
	int		i;
	int		y;

	y = 1;
	read = get_next_line(fd);
	while (read != NULL && y < map->size_y)
	{
		map->table[y] = (char *)malloc(sizeof(char) * (map->size_x + 1));
		if (!map->table[y])
			return (free(read));
		i = 0;
		while (read[i] && read[i] != '\n')
		{
			map->table[y][i] = read[i];
			i++;
		}
		map->table[y][i] = '\0';
		free(read);
		read = get_next_line(fd);
		y++;
	}
	map->table[y] = NULL;
}

int	count_collectibles(t_game *game)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (i < game->size_y)
	{
		j = 0;
		while (j < game->size_x)
		{
			if (game->table[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

t_game	*insert_map(char *filepath, t_game *map)
{
	int	fd;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (map);
	map = init_map(filepath, map, &fd);
	if (!map->table)
		return (map);
	fill_map(fd, map);
	close(fd);
	map->items_collected = 0;
	map->total_items = count_collectibles(map);
	return (map);
}
