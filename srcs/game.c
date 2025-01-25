/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Edwin ANNE <eanne@student.42lehavre.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:09:55 by Edwin ANNE        #+#    #+#             */
/*   Updated: 2025/01/25 23:13:37 by Edwin ANNE       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		free_exit(game);
	else if (keycode == KEY_W || keycode == KEY_UP)
		move(game, 'y', -1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move(game, 'x', -1);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move(game, 'y', 1);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move(game, 'x', 1);
	mlx_clear_window(game->mlx, game->win);
	render_map(game);
	return (0);
}

int	start_game(t_game *game)
{
	if (!game)
		return (1);
	game->move_counter = 0;
	game->total_items = count_collectibles(game);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (1);
	game = size_window(game);
	if (!game)
		return (free_map(game));
	game->win = mlx_new_window(game->mlx, game->width, game->height, "So Long");
	if (!game->win)
		return (free_map(game));
	game = upload_img(game);
	if (!game)
		return (free_map(game));
	render_map(game);
	return (1);
}
