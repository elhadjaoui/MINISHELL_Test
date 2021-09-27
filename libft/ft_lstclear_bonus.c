/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 21:38:34 by abenouda          #+#    #+#             */
/*   Updated: 2019/10/29 16:59:50 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next_node;
	t_list	*current;

	if (lst && del)
	{
		next_node = (*lst);
		current = (*lst);
		while (next_node != NULL)
		{
			current = next_node;
			next_node = next_node->next;
			(*del)(current->content);
			free(current);
		}
		*lst = NULL;
	}
}
