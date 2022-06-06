/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 10:32:48 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/06 13:56:12 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

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