/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanne <eanne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:22:03 by eanne             #+#    #+#             */
/*   Updated: 2024/10/21 13:00:55 by eanne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if ((unsigned char)*s == (unsigned char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if ((unsigned char)*s == (unsigned char)c)
	{
		return ((char *)s);
	}
	return (NULL);
}
