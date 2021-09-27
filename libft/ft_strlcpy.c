/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 19:57:12 by abenouda          #+#    #+#             */
/*   Updated: 2019/10/22 23:42:41 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (!src || !size)
		return (ft_strlen(src));
	if (src)
	{
		i = -1;
		while ((size_t)++i < size - 1 && src[i] != '\0')
			dst[i] = src[i];
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
