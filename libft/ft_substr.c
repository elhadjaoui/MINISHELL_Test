/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 22:05:09 by abenouda          #+#    #+#             */
/*   Updated: 2019/10/30 20:04:01 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*ptr;
	size_t		i;

	i = 0;
	if (s == 0)
		return (NULL);
	if (ft_strlen(s) <= start)
	{
		if (!(ptr = (char *)malloc(1)))
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	if (!(ptr = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (i < len)
	{
		ptr[i++] = s[start++];
	}
	ptr[i] = '\0';
	return (ptr);
}
