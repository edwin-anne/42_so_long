/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Edwin ANNE <eanne@student.42lehavre.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:53:20 by Edwin ANNE        #+#    #+#             */
/*   Updated: 2025/01/19 20:29:42 by Edwin ANNE       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game *size_window(t_game *game, t_map map)
{
	game->height = map.size_y * 40;
	game->width = map.size_x * 40;
return (game);
}

t_game *upload_img(t_game *game)
{
    int x;
    int y;

	x = 40;
	y = 40;
    game->img_1 = mlx_xpm_file_to_image(game->mlx, "sprite/1.xpm", &x, &y);
    game->img_0 = mlx_xpm_file_to_image(game->mlx, "sprite/0.xpm", &x, &y);
    game->img_c = mlx_xpm_file_to_image(game->mlx, "sprite/c.xpm", &x, &y);
    game->img_e = mlx_xpm_file_to_image(game->mlx, "sprite/e.xpm", &x, &y);
    game->img_p = mlx_xpm_file_to_image(game->mlx, "sprite/p.xpm", &x, &y);
	return (game);
}

void render_map(t_game *game, t_map map)
{
    int	y;
    int	x;

	y = 0;
    while (map.table[y])
	{
        x = 0;
        while (map.table[y][x])
		{
            if (map.table[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->win, game->img_1, x * 40, y * 40);
            else if (map.table[y][x] == '0')
                mlx_put_image_to_window(game->mlx, game->win, game->img_0, x * 40, y * 40);
            else if (map.table[y][x] == 'C')
                mlx_put_image_to_window(game->mlx, game->win, game->img_c, x * 40, y * 40);
            else if (map.table[y][x] == 'E')
                mlx_put_image_to_window(game->mlx, game->win, game->img_e, x * 40, y * 40);
            else if (map.table[y][x] == 'P')
                mlx_put_image_to_window(game->mlx, game->win, game->img_p, x * 40, y * 40);
            x++;
        }
        y++;
    }
}