/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_norm_functions1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 12:32:32 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/09/27 16:00:08 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	get_tokens_quoted1_state(t_token **token, char **line, int *state,
	t_all *all)
{
	char	*str;

	if (initialize_quoted1_state(line, &str) == -1)
		return (-1);
	while (**line && **line != ' ')
	{
		quoted1_state_norm3(line, &str, token, all);
		if (quoted1_state_norm(state, line, &str) == -1)
			return (-1);
		else if (**line == '"')
		{
			*state = QUOTE2;
			if (search_forNext_Dquote(line, &str, all, token) == -1)
				return (-1);
			else
				*state = NORMAL;
		}
		else if (ft_search4special_character("><|", **line))
			add_special_character_to_token(&str, token, line);
		else if (**line != '\'' && **line != '"' && **line != '$')
			str = ft_strjoinchar(str, **line);
		quoted1_state_norm2(line);
	}
	quoted1_state_norm1(token, &str);
	return (1);
}

void	handle_dollar_norm1(char **str, t_token **token, char **s)
{
	char	*space;
	char	*tmp;

	tmp = *s;
	while (*s && **s)
	{
		space = ft_strdup("");
		while (**s != ' ' && **s)
		{
			space = ft_strjoinchar(space, **s);
			(*s)++;
		}
		if (**s == ' ')
		{
			if (ft_strlen(*str))
			{
				tokadd_back(token, toknew(*str, TEXT));
				*str = ft_strdup("");
			}
			tokadd_back(token, toknew(space, TEXT));
		}
		if (**s == '\0')
			 *str = ft_strjoin1(*str, space);
		if (**s != '\0')
			(*s)++;
	}

}

void	handle_dollar_norm(char **line, t_all *all, char **str, t_token **token)
{
	char	*s;

	s = ft_strdup("");
	(*line)++;
	if (**line != '\0')
	{
		while (**line && ((**line <= 'z' && **line >= 'a')
				|| (**line <= 'Z' && **line >= 'A')
				|| (**line <= '9' && **line >= '0')))
		{
			s = ft_strjoinchar(s, **line);
			(*line)++;
		}
		s = grab_env(all->l_env, s);
		s = skip_whitespaces(s);
		handle_dollar_norm1(str, token, &s);
	}
}

void	handle_dollar_norm2(char **line, char **str, t_all *all)
{
	(*line)++;
	*str = ft_strjoin1(*str, ft_itoa(all->ex));
	(*line)++;
}

void	handle_dollar_norm3(char **line, char **str)
{
	(*line)++;
	*str = ft_strjoinchar(*str, '$');
	*str = ft_strjoinchar(*str, '=');
	(*line)++;
}
