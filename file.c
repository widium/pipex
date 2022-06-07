/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:24:14 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/07 18:16:21 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void here_doc(t_env *env)
{
    char *line;
    
    env->tmp_file->name = "tempo.txt";
    env->tmp_file->fd = open(env->tmp_file->name, O_CREAT | O_WRONLY , 0777);
    while (1)
    {
        line = get_next_line(STDIN_FILENO);
        if (!ft_strncmp(env->keyword, line, (ft_strlen(env->keyword))))
            break;
        else
            ft_putstr_fd(line, env->tmp_file->fd);
    }
    close(env->tmp_file->fd);
    env->tmp_file->fd = open(env->tmp_file->name, O_RDONLY);
    env->in_file = env->tmp_file;
    unlink(env->tmp_file->name);
}

int detect_in_file_or_keyword(t_env *env, char **argv, int argc)
{
    char *line;
    
    if (same_str(argv[1], "here_doc"))
    {
        if (argc == 4)
            return (0);
        env->keyword = argv[2];
        env->start = 3;
        return (2);
    }
    else 
    {
        env->in_file->name = argv[1];
        env->in_file->fd = open(env->in_file->name, O_RDONLY , 0777);
        env->start = 2;
        if (env->in_file->fd == -1)
            return (0);
        
    }
    return (1);
}

void detect_and_create_out_file(t_env *env, char **argv, int argc)
{
    env->out_file->name = argv[argc - 1];
    env->out_file->fd = open(env->out_file->name, O_CREAT | O_WRONLY | O_TRUNC, 0777);
}