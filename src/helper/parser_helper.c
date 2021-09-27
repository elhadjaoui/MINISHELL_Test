/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 12:44:57 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/09/27 12:09:57 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	get_env_value(t_token **token, char **string, t_all *all)
{
	char	*str;

	if ((*token)->next != NULL)
	{
		(*token) = (*token)->next;
		str = grab_env(all->l_env, (*token)->name);
		if (str != NULL)
			*string = ft_strjoin1(*string, str);
	}
	return (1);
}

int	get_qmark_value(t_token **token, char **string, t_all *all)
{
	char	*str;

	if ((*token)->next != NULL)
	{
		(*token) = (*token)->next;
		str = ft_itoa(all->ex);
		if (str != NULL)
			*string = ft_strjoin1(*string, str);
		*string = ft_strjoin1(*string, " ");
	}
	return (1);
}

// @ hada derto 7it knt k nspliti b space o w9a3 li mochkil o dert 
// chi character li nspliti bih s3ib itih 3lih chi had

void	join_characters(char **string, t_token *token)
{
	*string = ft_strjoin1(*string, token->name);
	*string = ft_strjoin1(*string, "@");
}

void	free_string(char **str)
{
	free(*str);
	*str = NULL;
}

int	check_cmd_starts(char *str, int num, t_all *all)
{
	if (*str == '|' && num != 1)
	{
		all->ex = 258;
		syntax_error("|");
		return (-1);
	}
	return (1);
}
