#include "so_long.h"
#include <stdio.h>

int handle_mouse(int button, int x, int y, void *param)
{
    (void)param;  // Pour éviter le warning de variable non utilisée
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
        free(game->mlx);
        return (1);
    }
    mlx_mouse_hook(game->win, &handle_mouse, NULL);
    return (0);
}
