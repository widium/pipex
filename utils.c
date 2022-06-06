/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 10:32:48 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/06 10:47:29 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

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

int is_first_cmd(t_command *cmd)
{
    if (cmd->index == 1)
        return (1);
    return (0);
}

int is_last_cmd(t_env *env, t_command *cmd)
{
    if (cmd->index == env->nbr_cmd)
        return (1);
    return (0);
}

void close_all(t_env *env)
{
   close(env->file->fd_in);
   close(env->file->fd_out);
   close(env->fd[0]);
   close(env->fd[1]);
   close(env->fd_next[0]);
   close(env->fd_next[1]);   
}