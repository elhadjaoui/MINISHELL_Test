/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helper1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 12:51:26 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/09/27 12:16:00 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	check_multiple_pipes(t_token *token, t_all *all)
{
	if (token->next == NULL)
	{
		all->ex = -1;
		error_multiline();
		return (-1);
	}
	if (cmp(token->next->name, "|"))
	{
		all->ex = 258;
		syntax_error("|");
		return (-1);
	}
	return (1);
}

int	check_next_token_after_redirection(char *str, char *str2, t_all *all)
{
	if (str2 == NULL || cmp(str2, str) || cmp(str2, "|"))
	{
		all->ex = 258;
		if (str2 == NULL)
			syntax_error("newline");
		else if (cmp(str2, "|"))
			syntax_error("|");
		else
			syntax_error(str);
		return (-1);
	}
	return (1);
}

int	parser_justForNorm(t_token **token, t_redirect **redirect,
	char **string, t_all *all)
{
	while (*token)
	{
		if (cmp((*token)->name, "|") && (*token)->num != -1)
			return (1);
		if ((*token)->num != -1)
		{
			if (check_wich_special_charcter(token, redirect, all) == -1)
				return (-1);
		}
		else
			join_characters(string, *token);
		*token = (*token)->next;
	}
	return (1);
}
