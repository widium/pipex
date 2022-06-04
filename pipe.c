/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:55:37 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/04 18:12:03 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

void manage_pipe(t_env *env)
{
    int i;
    t_command *iter;

    iter = env->first_cmd;
    i = 0;

    while (iter->next_cmd)
    {
        if (iter->next_cmd)
        {
            printf("Command -> (%d)\n", i);
        }
        iter = iter->next_cmd;
        i++;
    }
}

void pipex(t_env *env, t_command *cmd, int *fd, int *fd_next)
{
    int id;

    id = fork();
    
    // wait(id);
    if (id == 0)
    {
        printf("Child Process {%d}\n", id);
        // ====== Si c'est la 1er command === //
        if (cmd->index == 1)
        {
            printf("1er command\n");
        // ====== Redirection Input -> read in_file === //
            dup2(env->file->fd_in, STDIN_FILENO);
        }
        else
        {
        // ====== Redirection Input -> 1e pipe reception === //
            
            //si c'est une command impaire
            if (cmd->index % 2 != 0)
                dup2(fd_next[0], STDIN_FILENO);
            else
                dup2(fd[0], STDIN_FILENO);
        }
        if (cmd->index == env->nbr_cmd)
        {
            printf("Last command\n");
        // ====== Redirection Output -> write out_file === //
            dup2(env->file->fd_out, STDOUT_FILENO);
        }
        else 
        {
        // ====== Redirection Output -> 1er pipe send === //
        
        //si c'est une command impaire
        if (cmd->index % 2 != 0)
            dup2(fd[1], STDOUT_FILENO);
        else
            dup2(fd_next[1], STDOUT_FILENO);
        }
        
        close(env->file->fd_in);
        close(env->file->fd_out);
        close(fd[0]);
        close(fd[1]);
        close(fd_next[0]);
        close(fd_next[1]);    
        exec_command(cmd);
        perror("In command failure : "); 
        }
}

// void pipex(t_env *env, t_command *cmd, t_command *next_cmd)
// {
//     int id;
//     int id2;

//     // print_cmd(cmd);
//     // print_cmd(next_cmd);
//     pipe(env->fd);
//     pipe(env->fd_next);
    
//     printf("Nbr cmd -> (%d)\n", env->nbr_cmd);
//     fprintf(stderr, "in_file fd[%d]\n", env->file->fd_in);
//     fprintf(stderr,"out_file fd[%d]\n", env->file->fd_out);
//     fprintf(stderr,"1er pipe envoie fd[%d]\n", env->fd[1]);
//     fprintf(stderr,"1er pipe reception fd[%d]\n", env->fd[0]);
//     fprintf(stderr,"2e pipe envoie fd[%d]\n", env->fd_next[1]);
//     fprintf(stderr,"2e pipe reception fd[%d]\n", env->fd_next[0]);
    
    
//     id = fork();
    
//     wait(id);
//     if (id == 0)
//     {
//         printf("Child Process {%d}\n", id);
//         // ====== Si c'est la 1er command === //
//         if (cmd->index == 0)
//         {
//             printf("1er command\n");
//             // ====== Redirection Input -> read in_file === //
//             dup2(env->file->fd_in, STDIN_FILENO);
//             // ====== Redirection Output -> 1e pipe send === //
//             dup2(env->fd[1], STDOUT_FILENO);
            
//         }
//         else
//         {
//             // ====== Redirection Input -> 1e pipe reception === //
//             dup2(env->fd[0], STDIN_FILENO);
//             // ====== Redirection Output -> 2e pipe send === //
            
//             dup2(env->fd_next[1], STDOUT_FILENO);
            
            
//         }
//         close(env->fd[1]);
//         close(env->file->fd_in);
//         close(env->fd[0]);
//         close(env->fd_next[1]);
//         close(env->fd_next[0]);
//         close(env->file->fd_out);
        
//         exec_command(cmd);
//         perror("In command failure : "); 
//     }
//     else
//     {
//        printf("Parent Process {%d}\n", id);
//        id2 = fork();
       
//     //    wait(id2);
//        if (id2 == 0)
//        {
//             printf("2e Child Process {%d}\n", id);
//             // ====== Si c'est la Last command === //
//             if (next_cmd->index == env->nbr_cmd - 1)
//             {
//                 printf("Last command\n");
//                 // ====== Redirection Input -> 2e pipe reception === //
//                 //    fprintf(stderr,"2e pipe reception fd[%d]\n", env->fd_next[0]);
//                 dup2(env->fd[0], STDIN_FILENO);
//                     // ====== Redirection Output -> write out_file === //
//                 dup2(env->file->fd_out, STDOUT_FILENO);
//             }
//             else 
//             {
//                 // ====== Redirection Input -> 2e pipe reception === //
//                     dup2(env->fd_next[0], STDIN_FILENO);
//                     // ====== Redirection Output -> 1er pipe send === //
//                     dup2(env->fd[1], STDOUT_FILENO);
//             }
//             close(env->fd[0]);
//             close(env->fd[1]);
//             close(env->fd_next[0]);
//             close(env->fd_next[1]);
//             close(env->file->fd_in);
//             close(env->file->fd_out);
//             exec_command(next_cmd);
//             perror("Out command failure : "); 
//        }
//     }
//     env->fd[0] = env->fd_next[0];
//     env->fd[1] = env->fd_next[1];
//     fprintf(stderr, "fin des process !\n");
// }



// pipe(fd);
//     id = fork();
    
//     wait(id);
//     if (id == 0)
//     {
//         printf("Child Process [%d]\n", id);
//         dup2(env->file->fd_in, STDIN_FILENO);
//         dup2(fd[1], STDOUT_FILENO);
        
//         close(env->file->fd_in);
//         close(fd[1]);
//         close(fd[0]);
//         close(env->file->fd_out);
        
//         exec_command(env->in_command);
//         perror("In command failure : ");
//     }
//     else
//     {
//        printf("Parent Process [%d]\n", id);
//        dup2(fd[0], STDIN_FILENO);
//        dup2(env->file->fd_out, STDOUT_FILENO);
       
//        close(env->file->fd_in);
//        close(env->file->fd_out);
//        close(fd[0]);
//        close(fd[1]);
    
//        exec_command(env->out_command);
//        perror("Out command failure : ");
//     } 