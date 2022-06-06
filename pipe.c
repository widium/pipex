/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:55:37 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/06 13:52:33 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

void setup_pipe(t_env *env, t_command *cmd)
{
    // Si c'est pas la 2e et la derniere command
    if (cmd->index > 2 && cmd->index != env->nbr_cmd)
    {
        //Si c'est une command paire
        if (cmd->index % 2 == 0)
            pipe(env->fd_next);
        else
            pipe(env->fd);
    } 
}

void pipex(t_env *env, t_command *cmd)
{
    int id;

    id = fork();
    
    // wait(id);
    if (id == 0)
    {
        // printf("Child Process {%d}\n", id);
        command_redirection(env, cmd);
        close_all(env);
        exec_command(cmd);
        perror("In command failure : "); 
    }
}

void multi_pipex(t_env *env)
{
    t_command *cmd;

    cmd = env->first_cmd;
    pipe(env->fd);
    pipe(env->fd_next);
    
    while (cmd->next_cmd)
    {   
        setup_pipe(env, cmd);      
        pipex(env, cmd);
        cmd = cmd->next_cmd;
    } 
}