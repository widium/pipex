/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:52:55 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/06 14:53:09 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int terminal(char **argv, int argc, char **env_path, int verbose)
{
    t_env *env;
    t_command *cmd;
    
    env = init_env();
    if (!(manage_parsing(env, argv, argc, env_path)))
    {
        print_error();
        return (0);
    }
    multi_pipex(env);
    if (verbose == 1)
    {
        cmd = env->first_cmd;
        print_all_cmd(env, cmd);
    }
    return (1);
        
}