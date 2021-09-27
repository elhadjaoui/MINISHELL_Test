/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 02:05:22 by abenouda          #+#    #+#             */
/*   Updated: 2019/10/29 17:00:34 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list *currrent;

	currrent = lst;
	if (currrent == NULL)
		return (NULL);
	while (currrent->next != NULL)
		currrent = currrent->next;
	return (currrent);
}
