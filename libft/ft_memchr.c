/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanne <eanne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:21:53 by eanne             #+#    #+#             */
/*   Updated: 2024/10/21 15:23:50 by eanne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*string;
	char	test;
	size_t	i;

	i = 0;
	test = (char)c;
	string = (char *)s;
	while (i < n)
	{
		if (string[i] == test)
			return ((void *)(string + i));
		i++;
	}
	return (NULL);
}
