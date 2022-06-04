/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 09:56:56 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/04 12:56:11 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PIPEX_H 
 #define PIPEX_H


# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_file
{
    char *in;
    char *out;

    int fd_in;
    int fd_out;
}       t_file;

typedef struct s_command
{
    char *brut;
    char *bin;
    char *flags;
    char **complete;
    int index;
    struct s_command *next_cmd;
}       t_command;

typedef struct s_path
{
    char **list_of_path;
    char *all_path;
    char *path;
    char *path_bin;
}       t_path;

typedef struct s_env
{
    int nbr_cmd;
    int fd[2];
    int fd_next[2];
    t_file *file;
    t_path *path;
    t_command *first_cmd;
}       t_env;

t_command   *init_command(void);
t_path  *init_path(void);
t_file *init_file(void);
t_env *init_env(void);



// void create_command(t_command *command, char **argv);
void recover_path(t_env *env, char **env_path);
int create_command(t_env *env, t_command *command);
void exec_command(t_command *command);
void connect_cmd(t_command *first_command, t_command *next_command);

void count_cmd(t_env *env);
void print_cmd(t_command *cmd);
void print_all_cmd(t_command *cmd);
void print_table(t_env *env);

void parsing_argv(t_env *env, char **argv, int argc);
int test_argv(t_env *env);
int manage_parsing(t_env *env, char **argv, int argc, char **env_path);
void add_input(t_command *command, char *input);
void setup_cmd(t_env *env, t_command *cmd, char *argv, int index);

void pipex(t_env *env, t_command *cmd, int *fd, int *fd_next);


void manage_pipe(t_env *env);
#endif