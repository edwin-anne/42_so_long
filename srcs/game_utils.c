/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Edwin ANNE <eanne@student.42lehavre.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:53:20 by Edwin ANNE        #+#    #+#             */
/*   Updated: 2025/01/20 16:38:51 by Edwin ANNE       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*size_window(t_game *game)
{
	game->height = game->size_y * 40;
	game->width = game->size_x * 40;
	return (game);
}

t_game	*upload_img(t_game *game)
{
	int	x;
	int	y;

	x = 40;
	y = 40;
	game->img_1 = mlx_xpm_file_to_image(game->mlx, "sprite/1.xpm", &x, &y);
	game->img_0 = mlx_xpm_file_to_image(game->mlx, "sprite/0.xpm", &x, &y);
	game->img_c = mlx_xpm_file_to_image(game->mlx, "sprite/c.xpm", &x, &y);
	game->img_e = mlx_xpm_file_to_image(game->mlx, "sprite/e.xpm", &x, &y);
	game->img_p = mlx_xpm_file_to_image(game->mlx, "sprite/p.xpm", &x, &y);
	return (game);
}

void	render_map(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	while (g->table[y])
	{
		x = 0;
		while (g->table[y][x])
		{
			if (g->table[y][x] == '1')
				mlx_put_image_to_window(g->mlx, g->win,
					g->img_1, x * 40, y * 40);
			else if (g->table[y][x] == '0')
				mlx_put_image_to_window(g->mlx, g->win,
					g->img_0, x * 40, y * 40);
			else
				render_map_item(g, x, y);
			x++;
		}
		y++;
	}
}

void	render_map_item(t_game *g, int x, int y)
{
	if (g->table[y][x] == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->img_c, x * 40, y * 40);
	else if (g->table[y][x] == 'E')
		mlx_put_image_to_window(g->mlx, g->win, g->img_e, x * 40, y * 40);
	else if (g->table[y][x] == 'P')
		mlx_put_image_to_window(g->mlx, g->win, g->img_p, x * 40, y * 40);
}
