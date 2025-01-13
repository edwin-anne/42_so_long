/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanne <eanne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:21:43 by eanne             #+#    #+#             */
/*   Updated: 2024/10/16 16:47:58 by eanne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int character)
{
	int	result;

	result = 1;
	if (character < 'a' || character > 'z')
	{
		if (character < 'A' || character > 'Z')
		{
			result = 0;
		}
	}
	return (result);
}
