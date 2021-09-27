/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 23:56:23 by abenouda          #+#    #+#             */
/*   Updated: 2019/10/21 22:34:13 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*cdest;
	unsigned char	*csrc;
	int				i;

	cdest = (unsigned char*)dest;
	csrc = (unsigned char*)src;
	i = 0;
	while ((size_t)i < n)
	{
		if (csrc[i] != (unsigned char)c)
		{
			cdest[i] = csrc[i];
			i++;
		}
		else
		{
			cdest[i] = csrc[i];
			return (&dest[i + 1]);
		}
	}
	return (NULL);
}
