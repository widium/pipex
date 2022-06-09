/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 10:15:15 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/09 11:12:50 by ebennace         ###   ########.fr       */
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
	ft_putstr_fd("Error :\n", 1);
	ft_putstr_fd("- Fork Fail\n", 1);
	ft_putstr_fd("- Pipe Fail\n", 1);
	ft_putstr_fd("- dup2 Fail\n", 1);
	ft_putstr_fd("- execv Fail\n", 1);
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
	while (env->first_cmd)
	{
		free(env->first_cmd);
		env->first_cmd = env->first_cmd->next_cmd;
	}
	free(env->in_file);
	free(env->out_file);
	free(env->tmp_file);
	free(env->path);
	free(env);
}

void	malloc_exit(void)
{
	ft_putstr_fd("Malloc Fail\n", 1);
	exit(0);
}
