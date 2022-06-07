/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 09:56:56 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/07 16:23:46 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PIPEX_H 
 #define PIPEX_H


# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

// typedef struct s_file
// {
//     char *in;
//     char *out;

//     int fd_in;
//     int fd_out;
// }       t_file;

typedef struct s_file
{
    char *name;
    int fd;
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
    char *keyword;
    int  start;
    t_file *in_file;
    t_file *out_file;
    t_file *tmp_file;
    t_path *path;
    t_command *first_cmd;
}       t_env;

t_command   *init_command(void);
t_path  *init_path(void);
t_file *init_file(void);
t_env *init_env(void);


int detect_in_file_or_keyword(t_env *env, char **argv, int argc);
void detect_and_create_out_file(t_env *env, char **argv, int argc);
void here_doc(t_env *env);

void recover_path(t_env *env, char **env_path);
int create_command(t_env *env, t_command *command);
void exec_command(t_command *command);
void connect_cmd(t_command *first_command, t_command *next_command);
void create_chained_list(t_env *env, char **argv, int argc);

void print_char(char *str);
int	same_str(char *first, char *second);
int	str_comp_witout_n(char *first, char *second);
char *remove_n(char *str);

int is_first_cmd(t_command *cmd);
int is_last_cmd(t_env *env, t_command *cmd);
void count_cmd(t_env *env);

void print_cmd(t_command *cmd);
void print_all_cmd(t_env *env, t_command *cmd);
void print_error(void);

int check_input(t_env *env, char **argv, int argc);
int parsing_argv(t_env *env, char **argv, int argc);
int test_argv(t_env *env);
int manage_parsing(t_env *env, char **argv, int argc, char **env_path);
void add_input(t_command *command, char *input);
void setup_cmd(t_env *env, t_command *cmd, char *argv, int index);

void pipex(t_env *env, t_command *cmd);
void multi_pipex(t_env *env);

void setup_pipe(t_env *env, t_command *cmd);
void choose_pipe_send(t_env *env, t_command *cmd);
void choose_pipe_receive(t_env *env, t_command *cmd);
void command_redirection(t_env *env, t_command *cmd);
void close_all(t_env *env);

int terminal(char **argv, int argc, char **env_path, int verbose);

#endif