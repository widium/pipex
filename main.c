/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 09:56:51 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/06 10:35:34 by ebennace         ###   ########.fr       */
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

int main (int argc, char **argv, char **env_path)
{
    t_env *env;
    t_command *cmd;
    int result;
    
    
    env = init_env();
    
    
    if (!(manage_parsing(env, argv, argc, env_path)))
        printf("Error\n");
    // print_cmd(env->first_cmd);
    // print_all_cmd(iter);
    
    // printf("fd in_file [%d]\n", env->file->fd_in);
    // printf("fd out_file [%d]\n", env->file->fd_out);
    multi_pipex(env);
    
    
}

