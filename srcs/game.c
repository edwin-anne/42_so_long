/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanne <eanne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:09:55 by Edwin ANNE        #+#    #+#             */
/*   Updated: 2025/01/20 17:51:23 by eanne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	start_game(t_game *game)
{
	if (!game)
		return (1);
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
	mlx_hook(game->win, KEY_EXIT, 0, free_exit, game);
	// mlx_loop(game->mlx);
	return (1);
}
