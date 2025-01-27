/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Edwin ANNE <eanne@student.42lehavre.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:36:14 by Edwin ANNE        #+#    #+#             */
/*   Updated: 2025/01/27 14:36:11 by Edwin ANNE       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Cette fonction parcours le fichier pour regarder si les caracteres 
//present dans le fichier sont bien des valeurs de map
int	character_verif(char *verif, t_count *map_count)
{
	int	i;

	i = 0;
	while (verif[i])
	{
		if (verif[i] != '\n' && verif[i] != '\0')
		{
			if (verif[i] != '1' && verif[i] != '0'
				&& verif[i] != 'C' && verif[i] != 'E' && verif[i] != 'P')
				return (0);
			else
			{
				if (verif[i] == 'E')
					map_count->count_e++;
				if (verif[i] == 'P')
					map_count->count_p++;
				if (verif[i] == 'C')
					map_count->count_c++;
			}
		}
		i++;
	}
	return (1);
}

int	*game_size_verif(char *verif, int *back_size)
{
	int	size;

	size = ft_strlen(verif);
	if (verif[size - 1] == '\n')
		size--;
	if (*back_size == -1)
		*back_size = size;
	else if (*back_size != size)
		return (NULL);
	return (back_size);
}

int	map_closed(char *verif, int edge)
{
	int	size;
	int	i;

	i = 0;
	size = ft_strlen(verif) - 1;
	while (verif[i])
	{
		if (edge == 1 && verif[i] != '1')
		{
			return (1);
		}
		else if (edge == 0)
		{
			if (i == 0 || i == size - 1)
			{
				if (verif[i] != '1')
				{
					return (0);
				}
			}
		}
		i++;
	}
	return (1);
}

int	is_start_or_end(int position, int total_lines)
{
	if (position == 0 || position == total_lines - 1)
		return (1);
	return (0);
}

int	verif_item_doublon(t_count *map_count)
{
	if (map_count->count_e != 1)
		return (0);
	else if (map_count->count_p != 1)
		return (0);
	else if (map_count->count_c < 1)
		return (0);
	else
		return (1);
}
