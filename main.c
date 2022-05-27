/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 09:56:51 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/27 19:07:56 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

// exec_command(command);

int main(int argc, char **argv, char **env_path)
{
    int fd[2];
    int id;
    
    t_env *env;
    int result;

    env = init_env();
    if (!(manage_parsing(env, argv, argc, env_path)))
        printf("Error\n");
    pipe(fd);
    id = fork();
    
    wait(id);
    if (id == 0)
    {
        printf("Child Process [%d]\n", id);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
        exec_command(env->in_command);
        // perror("Error Execv : ");
    }
    else
    {
       printf("Parent Process [%d]\n", id);
       dup2(fd[0], STDIN_FILENO);
       close(fd[0]);
    //    close(env->file->fd_out);
       exec_command(env->out_command);
       
    //    exec_command(env->out_command);
    }
    

    
    
}