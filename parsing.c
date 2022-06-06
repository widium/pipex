/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:28:52 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/06 13:44:20 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

int manage_parsing(t_env *env, char **argv, int argc, char **env_path)
{
    int result;
    
    recover_path(env, env_path);
    parsing_argv(env, argv, argc);
    return (1);
}

void parsing_argv(t_env *env, char **argv, int argc)
{
    int i;
    int index;
    t_command *cmd;
    t_command *next_cmd;

    i = 2;
    index = 1;
    detect_and_open_files(env, argv, argc);
    create_chained_list(env, argv, argc);
    count_cmd(env);
}

void create_chained_list(t_env *env, char **argv, int argc)
{
    int i;
    int index;
    t_command *cmd;
    t_command *next_cmd;
    
    i = 2;
    index = 1;
    while (i < argc)
    {
        if (i < 3)
        {
            cmd = init_command();
            setup_cmd(env, cmd, argv[i], index);
            env->first_cmd = cmd;
        }
        else
        {
            next_cmd = init_command();
            setup_cmd(env, next_cmd, argv[i], index);
            connect_cmd(cmd, next_cmd);
            cmd = next_cmd;
        }
        i++ && index++;
    }
}



// void create_fd(t_env *env, t_command *cmd)
// {
//     int i;
//     int y;
//     t_command *first;
    
//     first = env->first_cmd;
//     i = 0;
    
//     while (i < env->nbr_cmd - 2)
//     {
//         pipe(env->fd[i]);
        
//         cmd->fd_receive = env->fd[i][0];
//         cmd->fd_send = env->fd[i][1];
        
//         printf("=========================\n");
//         printf("command_%d\n", i);
//         printf("[%d] -> reception\n", cmd->fd_receive);
//         printf("[%d] -> envoie \n", cmd->fd_send);
//         printf("=========================\n");

//         cmd = cmd->next_cmd->next_cmd;
        
//         i++;
//     }
    
// }

// void print_table(t_env *env)
// {
//     int i = 0;

//     while (env->fd[i])
//     {
//         printf("[%d]\n", env->fd[i]);
//         i++;
//     }
// }
// int test_argv(t_env *env)
// {
//     int result_2;
//     int result_3;
    
//     env->file->fd_in = open(env->file->in, O_CREAT | O_RDONLY , 0777);
//     env->file->fd_out = open(env->file->out, O_CREAT | O_WRONLY | O_TRUNC, 0777);
    
//     // env->in_command->complete = ft_split(env->in_command->brut, ' ');
//     // env->out_command->complete = ft_split(env->out_command->brut, ' ');
    
//     // create_command(env->in_command, env->in_command->complete);
//     // create_command(env->out_command, env->out_command->complete);

//     result_2 = test_command(env, env->in_command);
//     result_3 = test_command(env, env->out_command);
    
//     if (env->file->fd_in == -1 || env->file->fd_out == -1)
//     {
//         perror("ERR: ");
//         printf("IN[%d], OUT[%d]\n", env->file->fd_in, env->file->fd_out);
//         return (0);
//     }   
//     if (result_2 == 0 || result_3 == 0)
//     {
//         perror("ERR: ");
//         printf("command_in[%d], command_out[%d]\n", result_2, result_3);
//         return (0); 
//     }
        
//     // add_input(env->in_command, env->file->in);
    
//     printf("fd in_file (%d)\n", env->file->fd_in);
//     printf("1er command -> %s %s\n", env->in_command->complete[0], env->in_command->complete[1]);
//     printf("2e command -> %s %s\n", env->out_command->complete[0], env->out_command->complete[1]);
//     printf("fd out_file (%d)\n", env->file->fd_out);

//     return (1);
    
// }