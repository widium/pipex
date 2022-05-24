/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recover.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:40:59 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/24 14:19:24 by ebennace         ###   ########.fr       */
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

void recover_command(t_command *command, char **argv)
{
    command->bin = argv[1];
    command->flags = argv[2];
    command->bin = ft_strjoin("/", command->bin);
    // printf("command -> %s %s\n", command->bin, command->flags);
}


void recover_path(t_path *path, char **env)
{
    int i;

    i = -1;
    while (env[++i])
    {
        if (start_with(env[i], "PATH=") != NULL)
            path->all_path = start_with(env[i], "PATH=");
    }
    path->list_of_path = ft_split(&path->all_path[5], ':');
}

void create_command(t_path *path, t_command *command)
{
    int y;
    int fd;
    
    y = -1;
    while (path->list_of_path[++y])
    {
        path->path_bin = ft_strjoin(path->list_of_path[y], command->bin);
        fd = access(path->path_bin, X_OK & F_OK);
        if (fd == 0)
        {
            command->command[0] = path->path_bin;
            command->command[1] = command->flags;
            return;
        }
    }
    // printf("LIST_PATH ===> %s\n", path->list_of_path[y]);
}

void exec_command(t_command *command)
{
    printf("command -> %s \n", command->command[0]);
    printf("flags -> %s\n",command->command[1]);
    // command->command = malloc(sizeof(char *) * 2);
    // command->command[0] = path->path_bin;
    // command->command[1] = command->flags;
    execv(command->command[0], command->command);
}