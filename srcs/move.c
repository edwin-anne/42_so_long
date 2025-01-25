/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Edwin ANNE <eanne@student.42lehavre.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:16:54 by Edwin ANNE        #+#    #+#             */
/*   Updated: 2025/01/25 23:02:42 by Edwin ANNE       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(t_game *game, int *x, int *y)
{
	*y = 0;
	while (*y < game->size_y)
	{
		*x = 0;
		while (*x < game->size_x)
		{
			if (game->table[*y][*x] == 'P')
				return ;
			(*x)++;
		}
		(*y)++;
	}
}

void	modify_map(t_game *game, int new_x, int new_y)
{
	int	current_x;
	int	current_y;

	find_player(game, &current_x, &current_y);
	if (game->table[new_y][new_x] == 'C')
	{
		game->items_collected++;
		printf("\rItems collected: %d/%d",
			game->items_collected, game->total_items);
	}
	else if (game->table[new_y][new_x] == 'E')
	{
		if (game->items_collected == game->total_items)
		{
			free_exit(game);
			return ;
		}
		else
			return ;
	}
	game->table[current_y][current_x] = '0';
	game->table[new_y][new_x] = 'P';
}

void	move(t_game *game, char axis, int dir)
{
	int	new_x;
	int	new_y;
	int	current_x;
	int	current_y;

	if (!game || !game->table)
		return ;
	find_player(game, &current_x, &current_y);
	new_x = current_x;
	new_y = current_y;
	if (axis == 'x')
		new_x += dir;
	else if (axis == 'y')
		new_y += dir;
	if (new_y < 0 || new_x < 0
		|| new_y >= game->size_y || new_x >= game->size_x)
		return ;
	if (game->table[new_y][new_x] != '1')
		modify_map(game, new_x, new_y);
}
