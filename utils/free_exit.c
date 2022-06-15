/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 10:15:15 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/15 16:34:18 by ebennace         ###   ########.fr       */
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

void	error_exit(t_env *env)
{
	fprintf(stderr,"Error :\n");
	fprintf(stderr,"- Fork Fail\n");
	fprintf(stderr,"- Pipe Fail\n");
	fprintf(stderr,"- dup2 Fail\n");
	fprintf(stderr,"- execv Fail\n");
	free_all(env);
	exit(0);
}

void	parsing_exit(t_env *env)
{
	print_error();
	free_all(env);
	exit(0);
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

void	malloc_exit(void)
{
	ft_putstr_fd("Malloc Fail\n", 1);
	exit(0);
}

void free_array(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
}
