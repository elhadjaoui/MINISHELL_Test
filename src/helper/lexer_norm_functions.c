/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_norm_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 12:29:10 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/09/22 14:47:03 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	quoted1_state_norm1(t_token **token, char **str)
{
	if (ft_strlen(*str))
		tokadd_back(token, toknew(*str, TEXT));
}

void	quoted1_state_norm2(char **line)
{
	if (**line != '\0' && **line != ' ' && **line != '$')
		(*line)++;
}

void	quoted1_state_norm3(char **line, char **str, t_token **token,
		t_all *all)
{
	if (**line == '$')
		handle_dollar(line, all, str, token);
}

int	quoted1_state_norm(int *state, char **line, char **str)
{
	if (**line == '\'')
	{
		*state = QUOTE1;
		if (search_forNext_quote(line, str) == -1)
			return (-1);
		else
			*state = NORMAL;
	}
	return (1);
}

int	initialize_quoted1_state(char **line, char **str)
{
	*str = ft_strdup("");
	if (**line == '\0')
		return (return_error_norm());
	return (1);
}
