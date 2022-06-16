/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:55:37 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/16 18:39:07 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	initialize_pipe(t_env *env, t_command *cmd)
{
	if (cmd->index > 2 && cmd->index != env->nbr_cmd)
	{
		if (cmd->index % 2 == 0)
		{
			if (pipe(env->fd_next) == -1)
				error_exit(env, 2);
		}
		else
		{
			if (pipe(env->fd) == -1)
				error_exit(env, 3);
		}
	}
}

void	pipex(t_env *env, t_command *cmd)
{
	int	id;

	id = fork();
	if (id == -1)
		error_exit(env, 4);
	else if (id == 0)
	{
		command_redirection(env, cmd);
		close_all(env);
		exec_command(env, cmd);
	}
}

void	multi_pipex(t_env *env)
{
	t_command	*cmd;

	cmd = env->first_cmd;
	create_pipes(env);
	while (cmd->next_cmd)
	{
		initialize_pipe(env, cmd);
		pipex(env, cmd);
		cmd = cmd->next_cmd;
	}
}

void	create_pipes(t_env *env)
{
	if (pipe(env->fd) == -1)
		error_exit(env, 5);
	if (pipe(env->fd_next) == -1)
		error_exit(env, 6);
}
