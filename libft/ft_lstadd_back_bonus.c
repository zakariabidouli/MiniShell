/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbidouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:27:54 by zbidouli          #+#    #+#             */
/*   Updated: 2021/12/01 23:29:29 by zbidouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*it;

	if (lst == NULL || new == NULL)
		return ;
	else if (*lst == NULL)
		*lst = new;
	else
	{
		it = *lst;
		while (it->next != NULL)
			it = it->next;
		it->next = new;
	}
	return ;
}
