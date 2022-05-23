/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 09:56:51 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/23 18:25:40 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

// int found_function(char *command)
// {
    
// }

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
int main(int argc, char **argv, char **env)
{
    find_check_exe(argc, argv, env);
}

int find_check_exe(int argc, char **argv, char **env)
{
    char **arguments;
    int i;
    char *result;
    char **path;
    int fd;
    char *path_bin;

    i = -1;
    arguments = ft_split(argv[1], ' ');
    while (env[++i])
        if (start_with(env[i], "PATH=") != NULL)
            result = start_with(env[i], "PATH=");
    // printf("%s\n", result);
    path = ft_split(&result[5], ':');
    int y = -1;
    while (path[++y])
    {
        // printf("%s\n", path[y]);
        path_bin = ft_strjoin(path[y], "/ls");
        fd = access(path_bin, X_OK & F_OK);
        
        if (fd == 0)
        {
            printf("%s fd -> %d\n", path_bin, fd);
            execv(path_bin, argv);
        }
           
        // fd = access("ls", R_OK & W_OK & X_OK & F_OK);
        // printf("%d\n",fd)
    }
    
    
    
    
}