/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 10:51:39 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/09/27 17:37:09 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	add_special_character(t_token **token, char **line, int *state, char **str)
{
	// if (**line == '"')
	// {
	// 	*state = QUOTE2;
	// 	return (1);
	// }
	// if (**line == '\'')
	// {
	// 	*state = QUOTE1;
	// 	return (1);
	// }
	*state = NORMAL;
	if (ft_search4special_character("><|", **line))
		add_special_character_to_token(str, token, line);
	return (2);
}

void	display_parser(t_command *cmd)
{
	int	i;

	while (cmd)
	{
		i = 0;
		while (cmd->cmd[i])
		{
			printf("cmd/arg = (%s)\n", cmd->cmd[i]);
			i++;
		}
		while (cmd->redirect)
		{
			printf("redirect = (%s - %d)\n", cmd->redirect->name,
				cmd->redirect->type);
			cmd->redirect = cmd->redirect->next;
		}
		cmd = cmd->next;
		printf("-------------------\n");
	}
}

void    clear_token(t_token **lst, void (*del)(void*))
{
    t_token    *next_node;
    t_token    *current;

    if (lst && del)
    {
        next_node = (*lst);
        current = (*lst);
        while (next_node != NULL)
        {
            current = next_node;
            next_node = next_node->next;
            (*del)(current->name);
            free(current);
        }
        *lst = NULL;
    }
}

void    clear_parser(t_command **lst)
{
    t_command    *next_node;
    t_command    *current;
	int			i;

	i = 0;
    if (lst)
    {
        next_node = (*lst);
        current = (*lst);
        while (next_node != NULL)
        {
            current = next_node;
            next_node = next_node->next;
			while (current->cmd[i])
			{
                // printf("cmd = %s\n",current->cmd[i]);
				free(current->cmd[i]);
				i++;
			}
            i = 0;
			// printf("Here\n");
		    free(current->cmd); 
            clear_redirect(&current->redirect, free);
            free(current);
        }
        *lst = NULL;
    }
}

void    clear_redirect(t_redirect **lst, void (*del)(void*))
{
    t_redirect    *next_node;
    t_redirect    *current;

    if (lst && del)
    {
        next_node = (*lst);
        current = (*lst);
        while (next_node != NULL)
        {
            current = next_node;
            next_node = next_node->next;
            // (*del)(current->name
        	free(current);
        }
        *lst = NULL;
    }
}

void	ft_free(char **str)
{
	while (*str != NULL)
	{
		free(*str);
		str++;
	}
	free(str);
}
