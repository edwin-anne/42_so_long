/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Edwin ANNE <eanne@student.42lehavre.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:03:47 by Edwin ANNE        #+#    #+#             */
/*   Updated: 2025/01/19 20:59:22 by Edwin ANNE       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void destroy_images(t_game *game)
{
    if (!game || !game->mlx)
        return;
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

int free_map(t_game *game)
{
    if (!game)
        return (0);
    destroy_images(game);
    if (game->win && game->mlx)
    {
        mlx_destroy_window(game->mlx, game->win);
        game->win = NULL;
    }
    if (game->mlx)
    {
        mlx_destroy_display(game->mlx);
        free(game->mlx);
        game->mlx = NULL;
    }
    return (0);
}

int	free_exit(t_game *game)
{
    free_map(game);
    exit(0);
}