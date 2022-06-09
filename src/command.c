/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:36:08 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/09 10:38:09 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	create_command(t_env *env, t_command *command)
{
	int	y;
	int	fd;

	y = -1;
	while (env->path->list_of_path[++y])
	{
		env->path->path_bin = ft_strjoin(env->path->list_of_path[y],
				command->bin);
		fd = access(env->path->path_bin, X_OK & F_OK);
		if (fd == 0)
		{
			command->complete[0] = env->path->path_bin;
			command->complete[1] = command->flags;
			command->bin = command->complete[0];
			command->flags = command->complete[1];
			return (1);
		}
	}
	return (0);
}

void	setup_cmd(t_env *env, t_command *cmd, char *argv, int index)
{
	cmd->index = index;
	cmd->brut = argv;
	cmd->complete = ft_split(cmd->brut, ' ');
	cmd->bin = cmd->complete[0];
	cmd->flags = cmd->complete[1];
	cmd->bin = ft_strjoin("/", cmd->bin);
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

int	exec_command(t_command *command)
{	
	int	result;

	result = execv(command->complete[0], command->complete);
	return (result);
}