/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eanne <eanne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:02:09 by eanne             #+#    #+#             */
/*   Updated: 2024/10/22 19:11:12 by eanne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = lst;
	while (temp != NULL)
	{
		(*f)(temp->content);
		temp = temp->next;
		i++;
	}
}
