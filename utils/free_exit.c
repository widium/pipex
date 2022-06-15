/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 10:15:15 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/15 11:27:36 by ebennace         ###   ########.fr       */
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
	// free_all(env);
	exit(0);
}

void	parsing_exit(t_env *env)
{
	print_error();
	// free_all(env);
	exit(0);
}

void	free_all(t_env *env)
{
	fprintf(stderr,"==== Free all ====\n");
	// printf("Free argv_cpy\n");
	// free_array(argv_cpy);
	fprintf(stderr,"--- Free chained list cmd ----\n");
	free_cmd(env->first_cmd);
	free(env->in_file);
	free(env->out_file);
	free(env->tmp_file);
	free_array(env->path->list_of_path);
	free(env->path);
	free(env);
}

// void	free_cmd(t_command *cmd)
// {
// 	t_command	*iter;
// 	int			i;

// 	i = 0;

// 	free_array(cmd->complete);
// 	// free(cmd->flags);
// 	//free(cmd->brut);
// 	free(cmd->bin);
// 	free(cmd);
// }

void	free_cmd(t_command *cmd)
{
	t_command	*iter;

	while (cmd->next_cmd)
	{
		iter = cmd->next_cmd;
		fprintf(stderr,"-------\n");
		fprintf(stderr,"Free cmd %p\n", cmd);
		fprintf(stderr,"Free bin : %s\n", cmd->bin);
		free(cmd->bin);
		fprintf(stderr,"Free complete : %s %s\n", cmd->complete[0], cmd->complete[1]);
		free_array(cmd->complete);
		
		free(cmd);
		cmd = iter;
	}
	fprintf(stderr,"-------\n");
	fprintf(stderr,"Free cmd %p\n", cmd);
	fprintf(stderr,"Free bin : %s\n", cmd->bin);
	free(cmd->bin);
	printf("Free complete : %s %s\n", cmd->complete[0], cmd->complete[1]);
	free_array(cmd->complete);
	
	free(cmd);
}

// void free_rec(t_command *cmd)
// {
// 	if(cmd->next_cmd)
// 		free_rec(cmd->next_cmd);
// 	free_cmd(cmd);
// }

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
	// free(array[i]);
	free(array);
}
