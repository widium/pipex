/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 09:56:56 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/24 14:18:21 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PIPEX_H 
 #define PIPEX_H


# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"


typedef struct s_command
{
    char *bin;
    char *flags;
    char **command;
}       t_command;

typedef struct s_path
{
    char **list_of_path;
    char *all_path;
    char *path;
    char *path_bin;
}       t_path;

t_command   *init_command(void);
t_path  *init_path(void);



void recover_command(t_command *command, char **argv);
void recover_path(t_path *path, char **env);
void create_command(t_path *path, t_command *command);
void exec_command(t_command *command);


void find_check_exe(int argc, char **argv, char **env);

#endif