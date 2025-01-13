#include "so_long.h"
#include <stdio.h>

int handle_mouse(int button, int x, int y)
{
    printf("Click at position: x=%d, y=%d with button %d\n", x, y, button);
    return (0);
}

int start_game(t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
        return (1);
    game->win = mlx_new_window(game->mlx, game->width, game->height, "So Long");
    if (!game->win)
    {
        mlx_destroy_display(game->mlx);
        free(game->mlx);
        return (1);
    }
    mlx_mouse_hook(game->win, handle_mouse, game);
    return (0);
}
