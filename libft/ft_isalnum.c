/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanne <eanne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:21:41 by eanne             #+#    #+#             */
/*   Updated: 2024/10/17 17:40:19 by eanne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int character)
{
	int	result;

	result = 1;
	if (!ft_isalpha(character))
	{
		if (!ft_isdigit(character))
		{
			result = 0;
		}
	}
	return (result);
}
