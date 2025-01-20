/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Edwin ANNE <eanne@student.42lehavre.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:42:20 by Edwin ANNE        #+#    #+#             */
/*   Updated: 2025/01/20 13:07:14 by Edwin ANNE       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_items(t_game *data)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	count = 0;
	if (!data || !data->table)
	{
		return (0);
	}
	while (y < data->size_y)
	{
		if (!data->table[y])
			return (0);
		x = 0;
		while (x < data->size_x)
		{
			if (data->table[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

void	flood_fill(t_game *data, int y, int x)
{
	if (y < 0 || x < 0 || y >= data->size_y || x >= data->size_x)
	{
		return ;
	}
	if (data->copied[y][x] == '1' || data->copied[y][x] == '.')
		return ;
	if (data->copied[y][x] == 'E')
	{
		data->exit_reached = 1;
		return ;
	}
	else if (data->copied[y][x] == 'C')
	{
		data->items_collected++;
		data->copied[y][x] = '.';
	}
	else
		data->copied[y][x] = '.';
	flood_fill(data, y + 1, x);
	flood_fill(data, y - 1, x);
	flood_fill(data, y, x + 1);
	flood_fill(data, y, x - 1);
}

int	find_start(t_game *map)
{
	int	y;
	int	x;

	y = 0;
	if (!map || !map->table)
		return (0);
	while (y < map->size_y)
	{
		if (!map->table[y])
			return (0);
		x = 0;
		while (x < map->size_x)
		{
			if (map->table[y][x] == 'P')
			{
				map->start_y = y;
				map->start_x = x;
				return (1);
			}
			x++;
		}
		y++;
	}
	printf("Error: No starting position found in map\n");
	return (0);
}

int	flood_fill_init(t_game *data)
{
	if (!data || !data->table || !data->copied)
		return (0);
	data->items_collected = 0;
	data->exit_reached = 0;
	data->total_items = count_items(data);
	if (data->total_items == 0)
		return (0);
	if (!find_start(data))
		return (0);
	flood_fill(data, data->start_y, data->start_x);
	if (data->items_collected == data->total_items && data->exit_reached)
		return (1);
	return (0);
}
