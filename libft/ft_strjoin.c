/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanne <eanne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:40:43 by eanne             #+#    #+#             */
/*   Updated: 2024/10/21 15:57:03 by eanne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*copy;
	int		len;
	int		i;
	int		j;

	len = 0;
	i = 0;
	j = 0;
	len += ft_strlen(s1);
	len += ft_strlen(s2);
	copy = (char *)malloc((len + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	while (s1[j] != '\0')
		copy[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		copy[i++] = s2[j++];
	copy[i] = '\0';
	return (copy);
}
