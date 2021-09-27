/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 00:44:38 by abenouda          #+#    #+#             */
/*   Updated: 2019/10/23 21:21:11 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*csrc;
	char	*cdest;

	csrc = (char*)src;
	cdest = (char*)dest;
	if (!dest && !src)
		return (dest);
	if (cdest < csrc)
		return (ft_memcpy(dest, src, n));
	while (n--)
		cdest[n] = csrc[n];
	return (dest);
}
