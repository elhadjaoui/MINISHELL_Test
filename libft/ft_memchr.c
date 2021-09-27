/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:01:07 by abenouda          #+#    #+#             */
/*   Updated: 2019/10/21 22:37:34 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*cstr;
	int				i;

	cstr = (unsigned char*)str;
	i = -1;
	while ((size_t)++i < n)
		if (cstr[i] == (unsigned char)c)
			return (cstr + i);
	return (NULL);
}
