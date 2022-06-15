/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:36:08 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/15 17:44:09 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	create_command(t_env *env, t_command *command)
{
	int	y;
	int	fd;
	char *path_bin;

	y = -1;
	while (env->path->list_of_path[++y])
	{
		env->path->path_bin = ft_strjoin(env->path->list_of_path[y],
				command->bin);
		fd = access(env->path->path_bin, X_OK & F_OK);
		if (fd == 0)
		{
			free(command->bin);
			command->bin = ft_strcpy(env->path->path_bin);
			command->complete[0] = command->bin;
			command->complete[1] = command->flags;
			free(env->path->path_bin);
			return (1);
		}
		free(env->path->path_bin);
	}
	return (0);
}

void	setup_cmd(t_env *env, t_command *cmd, char *argv, int index)
{	
	cmd->index = index;
	cmd->brut = argv;
	cmd->complete = ft_split(cmd->brut, ' ');
	cmd->flags = cmd->complete[1];
	cmd->bin = ft_strjoin("/", cmd->complete[0]);
	create_command(env, cmd);
}

void	connect_cmd(t_command *first_command, t_command *next_command)
{
	if (!next_command)
		return ;
	first_command->next_cmd = next_command;
}

void	count_cmd(t_env *env)
{
	t_command	*iter;
	int			i;

	i = 0;
	iter = env->first_cmd;
	while (iter->next_cmd)
	{
		iter = iter->next_cmd;
		i++;
	}
	env->nbr_cmd = i;
}

void	exec_command(t_env *env, t_command *command)
{	
	int		result;

	// free_all(env);
	fprintf(stderr, "path : %s\n", command->complete[0]);
	fprintf(stderr, "complete : %s %s\n", command->complete[0], command->complete[1]);
	result = execve(command->complete[0], command->complete, env->env_path);
	if (result == -1)
		error_exit(env);
}
