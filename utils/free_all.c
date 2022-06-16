/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 10:15:15 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/16 19:27:50 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	close_all(t_env *env)
{
	close(env->in_file->fd);
	close(env->out_file->fd);
	close(env->fd[0]);
	close(env->fd[1]);
	close(env->fd_next[0]);
	close(env->fd_next[1]);
}

void	free_all(t_env *env)
{
	free_array(env->argv_cpy);
	free_cmd(env->first_cmd);
	free(env->in_file->name);
	free(env->in_file);
	free(env->out_file->name);
	free(env->out_file);
	free_array(env->path->list_of_path);
	free(env->path);
	free(env);
}

void	free_cmd(t_command *cmd)
{
	t_command	*iter;

	while (cmd->next_cmd)
	{
		iter = cmd->next_cmd;
		free(cmd->bin);
		free_array(cmd->complete);
		free(cmd);
		cmd = iter;
	}
	free(cmd->bin);
	free_array(cmd->complete);
	free(cmd);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
}
