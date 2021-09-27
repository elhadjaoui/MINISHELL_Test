/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:52:40 by abenouda          #+#    #+#             */
/*   Updated: 2019/10/29 17:14:03 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *cpy;
	t_list *head;

	if (!lst)
		return (NULL);
	cpy = ft_lstnew(f(lst->content));
	head = cpy;
	lst = lst->next;
	while (lst)
	{
		cpy->next = ft_lstnew(f(lst->content));
		if (!cpy)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		lst = lst->next;
		cpy = cpy->next;
	}
	return (head);
}
