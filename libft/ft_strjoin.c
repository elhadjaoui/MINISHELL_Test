/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:05:33 by abenouda          #+#    #+#             */
/*   Updated: 2021/09/24 15:02:17 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	int		len;
	int		i;
	int		j;
	char	*joinstr;

	len = 0;
	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if ((joinstr = (char*)malloc(len + 1)) == NULL)
		return (NULL);
	while (s1[i] != 0)
	{
		joinstr[j++] = s1[i++];
	}
	i = 0;
	while (s2[i] != 0)
	{
		joinstr[j++] = s2[i++];
	}
	joinstr[j] = '\0';
	return (joinstr);
}

char	*ft_strjoin1(char *s1, char const *s2)
{
	int		len;
	int		i;
	int		j;
	char	*joinstr;

	len = 0;
	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if ((joinstr = (char*)malloc(len + 1)) == NULL)
		return (NULL);
	while (s1[i] != 0)
	{
		joinstr[j++] = s1[i++];
	}
	i = 0;
	while (s2[i] != 0)
	{
		joinstr[j++] = s2[i++];
	}
	free(s1);
	joinstr[j] = '\0';
	return (joinstr);
}
