/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 09:56:51 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/24 11:46:30 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"



void find_check_exe(int argc, char **argv, char **env)
{
    char **arguments;
    int i;
    char *result;
    int fd;
    char *path_bin;
    t_command *command;
    t_path *path;

    command = init_command();
    path = init_path();

    
    recover_command(command, argv);
    // printf("command -> %s %s\n", command->bin, command->flags);

    recover_path(path, env);
    // printf("ALL_PATH ===> %s\n", path->all_path);

    create_and_test_path(path, command);

    
    exec_command(path, command);
    // execv(path->path_bin, &command->flags);
    // int y = -1;
    // while (path->list_of_path[++y])
    //     printf("LIST_PATH ===> %s\n", path->list_of_path[y]);
    
    // while (path[++y])
    // {
    //     // printf("%s\n", path[y]);
    //     path_bin = ft_strjoin(path[y], command->bin);
    //     fd = access(path_bin, X_OK & F_OK);
    //     printf("%s --> fd %d\n", path_bin, fd);
        
    //     if (fd == 0)
    //     {
            
    //         printf("path -> %s\n", path_bin);
    //         execv(path_bin, &flags);
    //     }
    // }
}

int main(int argc, char **argv, char **env)
{
    find_check_exe(argc, argv, env);
    return (0);
}