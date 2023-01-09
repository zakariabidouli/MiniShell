/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbidouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:39:50 by zbidouli          #+#    #+#             */
/*   Updated: 2021/12/01 23:40:17 by zbidouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*add;

	if (lst == NULL || f == NULL)
		return (NULL);
	ptr = NULL;
	while (lst)
	{
		add = ft_lstnew((*f)(lst->content));
		if (!add)
		{
			ft_lstclear(&ptr, del);
			return (NULL);
		}
		ft_lstadd_back(&ptr, add);
		add = add->next;
		lst = lst->next;
	}
	return (ptr);
}
