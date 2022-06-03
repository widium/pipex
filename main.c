/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 09:56:51 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/03 18:54:47 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

// exec_command(command);

int main(int argc, char **argv, char **env_path)
{
    int id;
    
    t_env *env;
    t_command *iter;
    int result;
    
    
    env = init_env();
    
    
    if (!(manage_parsing(env, argv, argc, env_path)))
        printf("Error\n");

    iter = env->first_cmd;
    // print_cmd(env->first_cmd);
    // print_all_cmd(iter);
    
    while (iter->next_cmd)
    {
        pipex(env, iter, iter->next_cmd);
        iter = iter->next_cmd;
    } 
    
}