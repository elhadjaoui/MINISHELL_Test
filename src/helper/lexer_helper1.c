/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_helper1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 10:41:05 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/09/27 17:55:48 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	search_for_special_character(char **line, char **str, t_token **token,
	t_all *all)
{
	if (**line == '$')
		handle_dollar(line, all, str, token);
	if (**line == '"')
	{
		if (search_forNext_Dquote(line, str, all, token) == -1)
			return (-1);
	}
	else if (**line == '\'')
	{
		if (search_forNext_quote(line, str) == -1)
			return (-1);
	}
	else if (ft_search4special_character("><|", **line))
		add_special_character_to_token(str, token, line);
	else if (**line != '$')
		*str = ft_strjoinchar(*str, **line);
	if (**line != '\0' && **line != ' ' && **line != '$')
		(*line)++;
	return (1);
}

int	search_forNext_quote(char **line, char **str)
{
	(*line)++;
	while (**line && **line != '\'')
	{
		*str = ft_strjoinchar(*str, **line);
		(*line)++;
	}
	if (**line != '\'')
	{
		error_multiline();
		return (-1);
	}
	return (1);
}

void	add_special_character_to_token(char **str, t_token **token, char **line)
{
	char	*special;

	if (ft_strlen(*str))
	{
		tokadd_back(token, toknew(*str, TEXT));
		*str = ft_strdup("");
	}
	special = malloc(sizeof(char) * 2);
	special[0] = **line;
	special[1] = '\0';
	tokadd_back(token, toknew(special, 200));
}

int	search_forNext_Dquote(char **line, char **str, t_all *all, t_token **token)
{
	(*line)++;
	while (**line && **line != '"')
	{
		if (**line == '$')
			handle_dollar(line, all, str, token);
		if (**line != '$' && **line != '"')
			*str = ft_strjoinchar(*str, **line);
		if (**line != '\0' && **line != '"'  && **line != '$')
			(*line)++;
	}
	if (**line == '\0')
	{
		error_multiline();
		return (-1);
	}
	return (1);
}
