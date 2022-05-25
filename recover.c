/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recover.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:40:59 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/25 11:32:38 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *start_with(char *str, char *start)
{
    int i;
    char *result;

    result = ft_strnstr(str, start, ft_strlen(str));
    // printf("%s\n",result);
    if (result != str)
        return (NULL);
    return (result);
    
}

void create_command(t_command *command, char **argv)
{
    command->bin = argv[0];
    command->flags = argv[1];
    command->bin = ft_strjoin("/", command->bin);
    // printf("command -> %s %s\n", command->bin, command->flags);
}


void recover_path(t_env *env, char **env_path)
{
    int i;

    i = -1;
    while (env_path[++i])
    {
        if (start_with(env_path[i], "PATH=") != NULL)
            env->path->all_path = start_with(env_path[i], "PATH=");
    }
    env->path->list_of_path = ft_split(&env->path->all_path[5], ':');
}

int test_command(t_env *env, t_command *command)
{
    int y;
    int fd;
    
    y = -1;
    while (env->path->list_of_path[++y])
    {
        env->path->path_bin = ft_strjoin(env->path->list_of_path[y], command->bin);
        fd = access(env->path->path_bin, X_OK & F_OK);
        if (fd == 0)
        {
            command->complete[0] = env->path->path_bin;
            command->complete[1] = command->flags;
            return (1);
        }
    }
    return (0);
    // printf("LIST_PATH ===> %s\n", path->list_of_path[y]);
}

void exec_command(t_command *command)
{
    printf("command -> %s \n", command->complete[0]);
    printf("flags -> %s\n",command->complete[1]);
    // command->command = malloc(sizeof(char *) * 2);
    // command->command[0] = path->path_bin;
    // command->command[1] = command->flags;
    execv(command->complete[0], command->complete);
}