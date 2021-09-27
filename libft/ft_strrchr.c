/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 19:18:25 by abenouda          #+#    #+#             */
/*   Updated: 2019/10/20 21:20:32 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = -1;
	while (s[++i])
		;
	while (i >= 0)
		if (s[i] == (char)c)
			return ((char*)s + i);
		else
			i--;
	return (NULL);
}
