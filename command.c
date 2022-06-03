/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:36:08 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/03 14:43:02 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

int create_command(t_env *env, t_command *command)
{
    int y;
    int fd;
    
    y = -1;
    while (env->path->list_of_path[++y])
    {
        env->path->path_bin = ft_strjoin(env->path->list_of_path[y], command->bin);
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
    // printf("LIST_PATH ===> %s\n", path->list_of_path[y]);
}

void setup_cmd(t_env *env, t_command *cmd, char *argv, int index)
{
	int result;
	
    cmd->index = index;
	cmd->brut = argv;
	cmd->complete = ft_split(cmd->brut, ' ');
	cmd->bin = cmd->complete[0];
	cmd->flags = cmd->complete[1];
	cmd->bin = ft_strjoin("/", cmd->bin);
	result = create_command(env, cmd);
}

void connect_cmd(t_command *first_command, t_command *next_command)
{
	if (!next_command)
		return ;
    first_command->next_cmd = next_command;
}

void print_cmd(t_command *cmd)
{
    printf("==================\n");
	printf("cmd complete -> %s %s\n", cmd->complete[0], cmd->complete[1]);
	printf("bin -> %s\n", cmd->bin);
	printf("flags -> %s\n", cmd->flags);
    printf("Index -> (%d)\n", cmd->index);
    printf("==================\n");
}

void print_all_cmd(t_command *cmd)
{
    while (cmd->next_cmd)
    {
        print_cmd(cmd);
        cmd = cmd->next_cmd;
    }
}

void count_cmd(t_env *env)
{
    int i;
    t_command *iter;

    i = 0;
    iter = env->first_cmd;
    while (iter->next_cmd)
    {
        iter = iter->next_cmd;
        i++;
    }
    env->nbr_cmd = i;
}