/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanne <eanne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:03:47 by Edwin ANNE        #+#    #+#             */
/*   Updated: 2025/01/20 17:57:50 by eanne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_images(t_game *game)
{
	if (game->img_1)
	{
		mlx_destroy_image(game->mlx, game->img_1);
		game->img_1 = NULL;
	}
	if (game->img_0)
	{
		mlx_destroy_image(game->mlx, game->img_0);
		game->img_0 = NULL;
	}
	if (game->img_c)
	{
		mlx_destroy_image(game->mlx, game->img_c);
		game->img_c = NULL;
	}
	if (game->img_e)
	{
		mlx_destroy_image(game->mlx, game->img_e);
		game->img_e = NULL;
	}
	if (game->img_p)
	{
		mlx_destroy_image(game->mlx, game->img_p);
		game->img_p = NULL;
	}
}

void	free_map_table(t_game *map, int i)
{
	if (map->table)
	{
		i = 0;
		while (i < map->size_y)
		{
			if (map->table[i])
				free(map->table[i]);
			i++;
		}
		free(map->table);
		map->table = NULL;
	}
	if (map->copied)
	{
		i = 0;
		while (i < map->size_y)
		{
			if (map->copied[i])
				free(map->copied[i]);
			i++;
		}
		free(map->copied);
		map->copied = NULL;
	}
}

int	free_map(t_game *game)
{
	if (!game)
		return (0);
	if (game || game->mlx)
		destroy_images(game);
	if (game->win && game->mlx)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
	if (game->mlx)
	{
		write(1, "h", 1);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
		write(1, "h", 1);
	}
	return (0);
}

int	free_exit(t_game *game)
{
	int	i;

	i = 0;
	free_map(game);
	free_map_table(game, i);
	write(1, "h", 1);
	exit(0);
}
