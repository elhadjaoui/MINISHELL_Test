/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenouda <abenouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 11:21:54 by mel-hadj          #+#    #+#             */
/*   Updated: 2021/09/21 16:33:01 by abenouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../headers/minishell.h"

// char	*if_non_forkable(char *cmd)
// {
// 	if (cmd)
// 	{
// 		if (!ft_strcmp(cmd, "cd"))
// 			return (cmd);
// 		else if (!ft_strcmp(cmd, "export"))
// 			return (cmd);
// 		else if (!ft_strcmp(cmd, "unset"))
// 			return (cmd);
// 		else if (!ft_strcmp(cmd, "exit"))
// 			return (cmd);
// 	}
// 	return (NULL);
// }

// char	*if_builtin(char *cmd)
// {
// 	if (!ft_strcmp(cmd, "echo"))
// 		return (cmd);
// 	else if (!ft_strcmp(cmd, "cd"))
// 		return (cmd);
// 	else if (!ft_strcmp(cmd, "pwd"))
// 		return (cmd);
// 	else if (!ft_strcmp(cmd, "export"))
// 		return (cmd);
// 	else if (!ft_strcmp(cmd, "unset"))
// 		return (cmd);
// 	else if (!ft_strcmp(cmd, "env"))
// 		return (cmd);
// 	else if (!ft_strcmp(cmd, "exit"))
// 		return (cmd);
// 	return (NULL);
// }

// void	exec_echo(t_command *cmd)
// {
// 	int	pid;

// 	pid = fork();
// 	if (!pid)
// 	{
// 		if (cmd->in)
// 		{
// 			dup2 (cmd->in, 0);
// 			close (cmd->in);
// 		}
// 		if (cmd->out != 1)
// 		{
// 			dup2 (cmd->out, 1);
// 			close (cmd->out);
// 		}
// 		ft_echo(cmd->cmd);
// 		exit(0);
// 	}
// }

// void	exec_export(t_command *cmd, t_list *env)
// {
// 	int	pid;

// 	pid = fork();
// 	if (!pid)
// 	{
// 		if (cmd->in)
// 		{
// 			dup2 (cmd->in, 0);
// 			close (cmd->in);
// 		}
// 		if (cmd->out != 1)
// 		{
// 			dup2 (cmd->out, 1);
// 			close (cmd->out);
// 		}
// 		if (!cmd->cmd[1])
// 			ft_export_na(env, 1);
// 		exit(0);
// 	}
// 	wait(NULL);
// }

// void	exec_env(t_command *cmd, t_list *env)
// {
// 	int	pid;

// 	pid = fork();
// 	if (!pid)
// 	{
// 		if (cmd->in)
// 		{
// 			dup2 (cmd->in, 0);
// 			close (cmd->in);
// 		}
// 		if (cmd->out != 1)
// 		{
// 			dup2 (cmd->out, 1);
// 			close (cmd->out);
// 		}
// 		if (cmd->cmd[1])
// 		{	
// 			ft_putstr_fd("env: ", 2);
// 			ft_putstr_fd(cmd->cmd[1], 2);
// 			ft_putstr_fd(": No such file or directory\n", 2);
// 		}
// 		else
// 			ft_env(env, 1);
// 		exit(0);
// 	}
// }

// void	exec_pwd(t_command *cmd)
// {
// 	int	pid;

// 	pid = fork();
// 	if (!pid)
// 	{
// 		if (cmd->in)
// 		{
// 			dup2 (cmd->in, 0);
// 			close (cmd->in);
// 		}
// 		if (cmd->out != 1)
// 		{
// 			dup2 (cmd->out, 1);
// 			close (cmd->out);
// 		}
// 		ft_pwd(1);
// 		exit(0);
// 	}
// 	wait(NULL);
// }

// void	exec_builtin(t_command *cmd, t_list *env)
// {
// 	if (!strcmp(cmd->cmd[0], "echo"))
// 		exec_echo(cmd);
// 	else if (!strcmp(cmd->cmd[0], "export"))
// 		exec_export(cmd, env);
// 	else if (!strcmp(cmd->cmd[0], "env"))
// 		exec_env(cmd, env);
// 	else if (!strcmp(cmd->cmd[0], "pwd"))
// 		exec_pwd(cmd);
// 	else
// 		return ;
// }
