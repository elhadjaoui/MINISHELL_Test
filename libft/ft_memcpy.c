/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:58:30 by abenouda          #+#    #+#             */
/*   Updated: 2019/10/21 22:37:14 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int		i;
	char	*cdest;
	char	*csrc;

	if (!dest && !src)
		return (dest);
	cdest = (char*)dest;
	if (src)
		csrc = (char*)src;
	i = 0;
	while ((size_t)i < n)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (dest);
}
