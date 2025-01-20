/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Edwin ANNE <eanne@student.42lehavre.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:54:30 by Edwin ANNE        #+#    #+#             */
/*   Updated: 2025/01/20 16:03:37 by Edwin ANNE       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_map(char *filepath)
{
	int			i_read;
	int			fd;
	int         size_verif;
	char		*read;
	int         lines_count;
	t_item_counter *map_count;
	
	i_read = 0;
	lines_count = count_line(filepath);
	fd = open(filepath, O_RDONLY);
	read = get_next_line(fd);
	size_verif = -1;
	map_count = ft_calloc(1, sizeof(t_item_counter));
	if (!map_count)
		return (0);
	while (read != NULL)
	{
		size_verif = game_size_verif(read, size_verif);
		if (!character_verif(read, map_count) || size_verif == -1)
		{
			free(map_count);
			free(read);
			return (0);
		}
		if (!map_closed(read, is_start_or_end(i_read, lines_count)))
		{
			free(map_count);
			free(read);
			return (0);
		}
		free(read);
		read = get_next_line(fd);
		i_read++;
	}
	free(read);
	close(fd);
	if (!verif_item_doublon(map_count))
	{
			free(map_count);
			return (0);
	}
	else
	{
		free(map_count);
		return (1);
	}
}

int main(int argc, char **argv)
{
	t_game *game;
	
	if (argc != 2)
		return (1);
	if (!check_map(argv[1]))
	{
		printf("error\n");
		return (1);
	}
	game = ft_calloc(1, sizeof(t_game));
	game = insert_map(argv[1], game);
	game = copy_map(game);
	
	if (!game->table || !game->copied)
		return (1);
	if (!game)
	{
		if (game->table)
			free_map_table(game);
		return (1);
	}
	if (start_game(game))
	{
		free_map_table(game);
		free(game);
		return (1);
	}
	
	return (0);
}