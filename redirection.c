/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 10:33:23 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/07 11:36:16 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

void choose_pipe_receive(t_env *env, t_command *cmd)
{
    //si c'est une command impaire
    if (cmd->index % 2 != 0)
        dup2(env->fd_next[0], STDIN_FILENO);
    else
        dup2(env->fd[0], STDIN_FILENO);
}

void choose_pipe_send(t_env *env, t_command *cmd)
{
    //si c'est une command impaire
    if (cmd->index % 2 != 0)
        dup2(env->fd[1], STDOUT_FILENO);
    else
        dup2(env->fd_next[1], STDOUT_FILENO);
}

void command_redirection(t_env *env, t_command *cmd)
{
    if (is_first_cmd(cmd))
        dup2(env->in_file->fd , STDIN_FILENO);  
    else
        choose_pipe_receive(env, cmd);
    if (is_last_cmd(env, cmd))
        dup2(env->out_file->fd, STDOUT_FILENO);
    else 
        choose_pipe_send(env, cmd);
}