/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadj <mel-hadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 12:12:20 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/09/27 13:20:50 by mel-hadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

void term_prompt()
{
	write(1, "<%%%%|==========> ", 18);
}

void ctrl_d()
{
	rl_replace_line("", 0);
	rl_redisplay();
	ft_putendl_fd("exit", 1);
	exit(0);
}

void ctrl_c(int num)
{
	t_all *all;

	all = all_init_static();
	all->ex = num + 128;
	if (!all->heredocfd)
	{
		write(1, "\n", 1);
		if (!all->fork)
			term_prompt();
	}
}

void ctrl_AS()
{
	t_all *all;

	all = all_init_static();
	if (all->fork == 1)
		ft_putendl_fd("Quit: 3", 1);
	else
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

t_all *all_init_static()
{
	static t_all all;

	return(&all);
}

void	init_all(t_all *all)
{
	all->l_cmd = NULL;
	all->l_env = NULL;
	all->l_history = NULL;
	all->env = NULL;
	all->line = NULL;
	all->ex = 0;
	all->fork = 0;
	all->heredocfd = 0;
}

int isNotEmpty(char *s)
{
	if (ft_strlen(s) == 0)
		return (0);
	return (1);
}

int		main(int argc, char **argv, char **env)
{
	t_all	*all;

	if (argc != 1)
		return (0);
	(void)argv;
	all = all_init_static();
	init_all(all);
	list_env(all, env);
	while (1)
	{
		signal(SIGINT, ctrl_c);
		signal(SIGQUIT, ctrl_AS);
		all->fork = 0;
		all->heredocfd = 0;
		all->line = readline("<%%%%|==========> ");
		if (!all->line)
		 	ctrl_d();
		if (all->line[0] != '\0')
			add_history (all->line);
		if (isNotEmpty(all->line))
		{
			if (parser(build_lexer(all), all) == 1)
			{
				int r = pipeline(all);
				clear_token(&all->token, free);
				clear_parser(&all->cmd);
				if (r)
					continue ;
			}
		}
		free(all->line);
	}
	return (1);
}