/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 10:33:23 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/09 10:37:53 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	choose_pipe_receive(t_env *env, t_command *cmd)
{
	if (cmd->index % 2 != 0)
	{
		if (dup2(env->fd_next[0], STDIN_FILENO) == -1)
			error_exit(env);
	}
	else
	{
		if (dup2(env->fd[0], STDIN_FILENO) == -1)
			error_exit(env);
	}
}

void	choose_pipe_send(t_env *env, t_command *cmd)
{
	if (cmd->index % 2 != 0)
	{
		if (dup2(env->fd[1], STDOUT_FILENO) == -1)
			error_exit(env);
	}
	else
	{
		if (dup2(env->fd_next[1], STDOUT_FILENO) == -1)
			error_exit(env);
	}
}

void	command_redirection(t_env *env, t_command *cmd)
{
	if (is_first_cmd(cmd))
	{
		if (dup2(env->in_file->fd, STDIN_FILENO) == -1)
			error_exit(env);
	}
	else
		choose_pipe_receive(env, cmd);
	if (is_last_cmd(env, cmd))
	{
		if (dup2(env->out_file->fd, STDOUT_FILENO) == -1)
			error_exit(env);
	}
	else
		choose_pipe_send(env, cmd);
}
