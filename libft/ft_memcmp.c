/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:09:48 by abenouda          #+#    #+#             */
/*   Updated: 2019/10/21 22:34:43 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*cstr1;
	unsigned char	*cstr2;
	size_t			i;

	cstr1 = (unsigned char*)str1;
	cstr2 = (unsigned char*)str2;
	i = 0;
	while (i < n)
	{
		if (cstr1[i] - cstr2[i] == 0)
			i++;
		else
			return (cstr1[i] - cstr2[i]);
	}
	return (0);
}
