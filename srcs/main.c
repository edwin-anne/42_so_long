/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Edwin ANNE <eanne@student.42lehavre.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:54:30 by Edwin ANNE        #+#    #+#             */
/*   Updated: 2025/01/28 22:10:39 by Edwin ANNE       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (1);
	if (!check_map(argv[1]))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	game = ft_calloc(1, sizeof(t_game));
	game = insert_map(argv[1], game);
	game = copy_map(game);
	if (!game->table || !game->copied)
		return (1);
	if (!flood_fill_init(game) || !game)
	{
		write(1, "Error\n", 6);
		if (game->table)
			free_map_table(game, 1);
		return (1);
	}
	start_game(game);
	mlx_hook(game->win, 2, 1L, ft_key_hook, game);
	mlx_hook(game->win, 17, 0, free_exit, game);
	mlx_loop(game->mlx);
}
