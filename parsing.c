/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:28:52 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/06 14:51:28 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

int manage_parsing(t_env *env, char **argv, int argc, char **env_path)
{
    int result;
    
    recover_path(env, env_path);
    if (!(parsing_argv(env, argv, argc)))
        return (0);
    return (1);
}

int parsing_argv(t_env *env, char **argv, int argc)
{
    int i;
    int index;
    t_command *cmd;
    t_command *next_cmd;

    i = 2;
    index = 1;
    if (!(check_input(env, argv, argc)))
        return (0);
    create_chained_list(env, argv, argc);
    count_cmd(env);
    return (1);
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

int check_input(t_env *env, char **argv, int argc)
{
    if (argc == 1)
        return (0);
    detect_and_open_files(env, argv, argc);
    if (env->file->fd_in == -1)
        return (0);
    return (1);
}