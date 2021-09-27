/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 11:13:07 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/09/27 19:01:48 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

// int	quoted2_state_initialize(char **str, bool *check_for_Dquote, char **line)
// {
// 	*str = ft_strdup("");
// 	*check_for_Dquote = true;
// 	(*line)++;
// 	if (**line == '\0')
// 		return (return_error_norm());
// 	return (1);
// }

// int	get_tokens_quoted2_state(t_token **token, char **line, int *state,
// 	t_all *all)
// {
// 	char	*str;
// 	bool	check_for_Dquote;

// 	if (quoted2_state_initialize(&str, &check_for_Dquote, line) == -1)
// 		return (-1);
// 	while (**line && **line != ' ')
// 	{
// 		while (**line && **line != '"' && check_for_Dquote)
// 		{
// 			if (**line == '$')
// 				handle_dollar(line, all, &str, token);
// 			if (**line != '$' && **line != '"')
// 				str = ft_strjoinchar(str, **line);
// 			if (**line != '\0' && **line != '"' && **line != '$')
// 				(*line)++;
// 		}
// 		if (**line == '$')
// 			handle_dollar(line, all, &str, token);
// 		check_other_cases(line, &check_for_Dquote, state);
// 		if (check_other_cases1(token, line, &str, check_for_Dquote) == -1)
// 			return (-1);
// 	}
// 	if (ft_strlen(str))
// 		tokadd_back(token, toknew(str, TEXT));
// 	return (1);
// }

int	get_tokens_normal_state(t_token **token, char **line, int *state,
	t_all *all)
{
	char	*str;

	str = ft_strdup("");
	while (**line && **line != ' ')
	{
		if (**line == '$')
			handle_dollar(line, all, &str, token);
		if (add_special_character(token, line, state, &str) == 1)
			return (1);
		if (!ft_search4special_character(SPECIAL_C1, **line))
		{
			while (**line && **line != ' ')
			{
				if (search_for_special_character(line, &str, token, all) == -1)
					return (-1);
			}
		}
		if (**line != '\0' && **line != ' ' && **line != '$')
			(*line)++;
	}
	if (ft_strlen(str))
		tokadd_back(token, toknew(str, TEXT));
	return (1);
}

int	check_state(int *state, t_token **token, char **line, t_all *all)
{
	if (*state == NORMAL)
	{
		if (get_tokens_normal_state(token, line, state, all) == -1)
		{
			all->ex = -1;
			return (-1);
		}
	}
	// if (*state == QUOTE1)
	// {
	// 	if (get_tokens_quoted1_state(token, line, state, all) == -1)
	// 	{
	// 		all->ex = -1;
	// 		return (-1);
	// 	}
	// }
	// if (*state == QUOTE2)
	// {
	// 	if (get_tokens_quoted2_state(token, line, state, all) == -1)
	// 	{
	// 		all->ex = -1;
	// 		return (-1);
	// 	}
	// }
	return (1);
}

t_token	*build_lexer(t_all *all)
{
	int		state;
	char	*line;
	t_token	*token;

	token = NULL;
	state = NORMAL;
	line = all->line;
	line = skip_whitespaces(line);
	while (*line)
	{
		if (check_state(&state, &token, &line, all) == -1)
			return (NULL);
		if ((*line) != '\0' && (*line) != '$')
			line++;
	}
	// if (state == QUOTE1 || state == QUOTE2)
	// {
	// 	error_multiline();
	// 	return (NULL);
	// }
	display_token(token);
	return (token);
}
