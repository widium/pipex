/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 09:56:51 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/04 19:17:34 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

// exec_command(command);

int main(int argc, char **argv, char **env_path)
{
    int id;
    int fd[2];
    int fd_next[2];
    
    t_env *env;
    t_command *cmd;
    int result;
    
    
    env = init_env();
    
    
    if (!(manage_parsing(env, argv, argc, env_path)))
        printf("Error\n");

    cmd = env->first_cmd;
    // print_cmd(env->first_cmd);
    // print_all_cmd(iter);
    
    printf("fd in_file [%d]\n", env->file->fd_in);
    printf("fd out_file [%d]\n", env->file->fd_out);
    
    pipe(fd);
    pipe(fd_next);
    
    while (cmd->next_cmd)
    {
        // Si c'est pas la 2e et la derniere command
        if (cmd->index > 2 && cmd->index != env->nbr_cmd)
        {
            //Si c'est une command paire
            if (cmd->index % 2 == 0)
                pipe(fd_next);
            else
                pipe(fd);
        }
        // printf("fd in [%d]\n", fd[0]);
        // printf("fd out [%d]\n", fd[1]);
        
        pipex(env, cmd, fd, fd_next);
        cmd = cmd->next_cmd;
    } 
    
}