/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanne <eanne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:18:36 by Edwin ANNE        #+#    #+#             */
/*   Updated: 2025/01/29 08:30:51 by eanne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_line(char *read, int *size_verif,
				t_count *map_count, int is_start_end)
{
	int	*result;

	result = game_size_verif(read, size_verif);
	if (!result || !character_verif(read, map_count))
		return (0);
	if (!map_closed(read, is_start_end))
		return (0);
	return (1);
}

int	read_lines(int fd, int line_count, t_count *map_count)
{
	int		i_read;
	char	*read;
	int		size_verif;

	i_read = 0;
	size_verif = -1;
	read = get_next_line(fd);
	while (read != NULL)
	{
		if (!check_line(read, &size_verif, map_count,
				is_start_or_end(i_read, line_count)))
		{
			close(fd);
			free(read);
			return (0);
		}
		free(read);
		read = get_next_line(fd);
		i_read++;
	}
	close(fd);
	return (1);
}

int	read_and_verify_map(char *filepath, t_count *map_count, int *line_count)
{
	int	fd;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
	{
		return (0);
	}
	if (!read_lines(fd, *line_count, map_count))
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int	final_checks(t_count *map_count)
{
	if (!verif_item_doublon(map_count))
	{
		free(map_count);
		return (0);
	}
	free(map_count);
	return (1);
}

int	check_map(char *filepath)
{
	int		line_count;
	t_count	*map_count;

	line_count = count_line(filepath);
	map_count = ft_calloc(1, sizeof(t_count));
	if (!map_count)
	{
		return (0);
	}
	if (!read_and_verify_map(filepath, map_count, &line_count))
	{
		return (0);
	}
	return (final_checks(map_count));
}
