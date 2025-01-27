/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Edwin ANNE <eanne@student.42lehavre.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:21:58 by Edwin ANNE        #+#    #+#             */
/*   Updated: 2025/01/27 14:31:18 by Edwin ANNE       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	map_size(char **map)
{
	int	size;

	size = 0;
	while (map[size] != NULL)
	{
		size++;
	}
	return (size);
}

int	count_line(char *filepath)
{
	int		fd;
	int		i;
	char	*read;

	fd = open(filepath, O_RDONLY);
	read = get_next_line(fd);
	i = 0;
	while (read != NULL)
	{
		i++;
		free(read);
		read = get_next_line(fd);
	}
	free(read);
	close(fd);
	return (i);
}

void	print_map(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			write(1, &map[y][x], 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

t_game	*copy_map(t_game *map)
{
	int	i;
	int	size;

	i = 0;
	if (!map->table)
		return (map);
	size = map_size(map->table);
	map->copied = malloc((size + 1) * sizeof(char *));
	if (!map->copied)
		return (map);
	while (i < size)
	{
		map->copied[i] = ft_strdup(map->table[i]);
		if (!map->copied[i])
		{
			while (--i >= 0)
				free(map->copied[i]);
			free(map->copied);
			map->copied = NULL;
			return (map);
		}
		i++;
	}
	map->copied[size] = NULL;
	return (map);
}

int	*ft_strlen_map(const char *s)
{
	int	*nbr_string;
	int	i;

	nbr_string = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != '\n' && s[i] != '\0')
			nbr_string++;
		i++;
	}
	return (nbr_string);
}
