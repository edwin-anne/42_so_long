/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanne <eanne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:22:20 by eanne             #+#    #+#             */
/*   Updated: 2024/10/17 17:22:56 by eanne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	nbr_string;

	nbr_string = 0;
	while (s[nbr_string])
	{
		nbr_string++;
	}
	return (nbr_string);
}
