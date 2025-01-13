/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanne <eanne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:21:38 by eanne             #+#    #+#             */
/*   Updated: 2024/10/17 17:39:50 by eanne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	size_t	i;
	size_t	total_size;
	void	*ptr;

	total_size = elementCount * elementSize;
	ptr = malloc(total_size);
	if (ptr == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < total_size)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
