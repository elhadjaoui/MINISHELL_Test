/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:34:40 by abenouda          #+#    #+#             */
/*   Updated: 2019/10/30 20:27:08 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_conststrlen(char const *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

static int			ft_isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int			ft_nbset(char const *s1, char const *set)
{
	int	idx;
	int	nb;
	int	end;

	idx = 0;
	nb = 0;
	while (ft_isset(s1[idx], set) == 1 && s1[idx])
	{
		nb++;
		idx++;
	}
	end = ft_conststrlen(s1);
	while (ft_isset(s1[end], set) == 1 && end > 0)
	{
		nb++;
		end--;
	}
	return (nb);
}

static int			ft_nbsetmax(char const *s1, char const *set)
{
	int	len;

	len = ft_conststrlen(s1) - 1;
	while (ft_isset(s1[len], set) == 1 && len > 0)
		len--;
	return (len);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		idx;
	int		min;
	int		max;
	int		len;

	if (!set || !s1)
		return (NULL);
	min = 0;
	while (ft_isset(s1[min], set) == 1)
		min++;
	max = ft_nbsetmax(s1, set);
	len = ft_strlen((char *)s1) - ft_nbset(s1, set);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (res == 0)
		return (0);
	idx = 0;
	while (min <= max)
	{
		res[idx] = s1[min];
		min++;
		idx++;
	}
	res[idx] = '\0';
	return (res);
}
