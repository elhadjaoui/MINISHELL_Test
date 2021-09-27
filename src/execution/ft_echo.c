/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:12:35 by abenouda          #+#    #+#             */
/*   Updated: 2021/09/20 15:13:20 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	echo_core(char **arg, int *n, int i, int j)
{
	if (arg[i][0] == '-')
	{
		*n = 0;
		while (arg[i][++j] != '\0')
		{
			if (arg[i][j] != 'n')
			{
				*n = 1;
				break ;
			}
		}
	}
	if (!*n)
		i++;
	while (arg[i])
	{
		printf("%s", arg[i]);
		i++;
		if (arg[i] && arg[i][0] != '\0')
			printf(" ");
	}
}

void	ft_echo(char **arg)
{
	int	i;
	int	j;
	int	n;

	i = 1;
	j = 0;
	n = 1;
	if (arg[1])
		echo_core(arg, &n, i, j);
	if (n)
		printf("\n");
}
