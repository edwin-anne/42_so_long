/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanne <eanne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:11:49 by eanne             #+#    #+#             */
/*   Updated: 2024/10/21 15:30:19 by eanne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*copy;
	size_t	str_len;
	size_t	i;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_strdup(""));
	if (len > str_len - start)
		len = str_len - start;
	copy = (char *)malloc((len + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		copy[i] = s[start + i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
