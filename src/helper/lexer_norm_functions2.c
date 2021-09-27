/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_norm_functions2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 12:36:04 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/09/27 15:13:06 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	handle_dollar(char **line, t_all *all, char **str, t_token **token)
{
	char	*string;
	char	*tmp;

	string = *line + 1;
	tmp = *str;
	if (ft_search4special_character("\\;|\"", *string) || *string == '\0')
	{
		(*line)++;
		*str = ft_strjoinchar(*str, '$');
		if (**line && **line != '\"')
			(*line)++;
	}
	else if ((*string <= '9' && *string >= '0'))
	{
		(*line)++;
		(*line)++;
	}
	else if (*string == '=')
		handle_dollar_norm3(line, str);
	else if (ft_search4special_character("?", *string))
		handle_dollar_norm2(line, str, all);
	else
		handle_dollar_norm(line, all, str, token);
}

int	check_other_cases1(t_token **token, char **line, char **str, bool check_for_Dquote)
{
	if (**line == '\'')
	{
		if (search_forNext_quote(line, str) == -1)
			return (-1);
	}
	else if (ft_search4special_character("><|", **line))
		add_special_character_to_token(str, token, line);
	else if (**line != '\'' && **line != '"' && **line != '$')
		*str = ft_strjoinchar(*str, **line);
	if (**line != '\0' && **line != ' ' && **line != '$')
		(*line)++;
	while (**line == ' ' && check_for_Dquote)
	{
		*str = ft_strjoinchar(*str, **line);
		(*line)++;
	}
	return (1);
}

void	check_other_cases(char **line, bool *check_for_Dquote, int *state)
{
	if (**line == '\"')
	{
		*check_for_Dquote = !(*check_for_Dquote);
		if (!*check_for_Dquote)
			*state = NORMAL;
		else
			*state = QUOTE2;
	}
}

int	check_wich_special_charcter(t_token **token, t_redirect **redirect,
	t_all *all)
{
	char	*str;
	int		num;

	str = (*token)->name;
	num = (*token)->num;
	all->ex = 1;
	if (cmp(str, ">"))
		 if (redirect_output(token, redirect, all) == -1)
			return (-1);
	if (cmp(str, "<"))
		if (redirect_input(token, redirect, all) == -1)
			 return (-1);
	return (1);
}
