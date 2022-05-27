/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:28:52 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/27 18:52:53 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

int manage_parsing(t_env *env, char **argv, int argc, char **env_path)
{
    int result;
    
    if (!(parsing_argv(env, argv, argc)))
        return (0);
    recover_path(env, env_path);
    if (!(test_argv(env)))
        return (0);
    return (1);
}

int parsing_argv(t_env *env, char **argv, int argc)
{
    if (argc > 5)
        return (0);
    env->file->in = argv[1];
    env->in_command->brut = argv[2];
    env->out_command->brut = argv[3];
    env->file->out = argv[4];
    return (1);
}

int test_argv(t_env *env)
{
    int result_2;
    int result_3;
    
    env->file->fd_in = open(env->file->in, O_CREAT | O_RDONLY , 0777);
    env->file->fd_out = open(env->file->out, O_CREAT | O_WRONLY | O_TRUNC, 0777);
    
    env->in_command->complete = ft_split(env->in_command->brut, ' ');
    env->out_command->complete = ft_split(env->out_command->brut, ' ');
    
    create_command(env->in_command, env->in_command->complete);
    create_command(env->out_command, env->out_command->complete);

    result_2 = test_command(env, env->in_command);
    result_3 = test_command(env, env->out_command);
    
    if (env->file->fd_in == -1 || env->file->fd_out == -1)
    {
        perror("ERR: ");
        printf("IN[%d], OUT[%d]\n", env->file->fd_in, env->file->fd_out);
        return (0);
    }   
    if (result_2 == 0 || result_3 == 0)
    {
        perror("ERR: ");
        printf("command_in[%d], command_out[%d]\n", result_2, result_3);
        return (0); 
    }
        
    
    printf("fd in_file (%d)\n", env->file->fd_in);
    printf("1er command -> %s %s\n", env->in_command->complete[0], env->in_command->complete[1]);
    printf("2e command -> %s %s\n", env->out_command->complete[0], env->out_command->complete[1]);
    printf("fd out_file (%d)\n", env->file->fd_out);

    return (1);
    
}