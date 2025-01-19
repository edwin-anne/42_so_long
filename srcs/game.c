#include "so_long.h"
#include <stdio.h>

int start_game(t_game *game, t_map map)
{
    if (!game)
        return (1);
    game->mlx = mlx_init();
    if (!game->mlx)
        return (1);
    game = size_window(game, map);
    if (!game)
        return (free_map(game));
    game->win = mlx_new_window(game->mlx, game->width, game->height, "So Long");
    if (!game->win)
        return (free_map(game));
    game = upload_img(game);
    if (!game)
        return (free_map(game));
    render_map(game, map);
    mlx_hook(game->win, KEY_EXIT, 0, free_exit, game);
    mlx_loop(game->mlx);
    return (0);
}
