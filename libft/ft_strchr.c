/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:50:42 by abenouda          #+#    #+#             */
/*   Updated: 2019/10/20 23:46:06 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int j;

	j = 0;
	while (s[j])
		j++;
	i = 0;
	while (i <= j)
		if (s[i] == (char)c)
			return ((char*)s + i);
		else
			i++;
	return (NULL);
}
