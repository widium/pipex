/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:55:45 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/07 16:18:47 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void print_cmd(t_command *cmd)
{
    printf("==================\n");
	printf("CMD : %s %s\n", cmd->complete[0], cmd->complete[1]);
	printf("bin : %s\n", cmd->bin);
	printf("flags : %s\n", cmd->flags);
    printf("Index : (%d)\n", cmd->index);
    printf("==================\n");
}

void print_all_cmd(t_env *env, t_command *cmd)
{
    printf("==================\n");
    printf("Name : %s\n", env->in_file->name);
    printf("Fd : [%d]\n", env->in_file->fd);
    printf("==================\n");
    while (cmd->next_cmd)
    {
        print_cmd(cmd);
        cmd = cmd->next_cmd;
    }
    printf("==================\n");
    printf("Name : %s\n", env->out_file->name);
    printf("Fd : [%d]\n", env->out_file->fd);
    printf("==================\n");
}

void print_error(void)
{
    printf("========= Error =========\n");
    printf("\nExample Input : \n\nfile_in \"cmd_1\" \"cmd_2\" out_file\n\n");
    printf("here_doc KEYWORD \"cmd_1\" \"cmd_2\" out_file\n");
    printf("--------");
    printf("\nErreur Frequentes :\n\n");
    printf("- Oublie du in_file\n");
    printf("- Oublie du out_file\n");
    printf("- Oublie des \" \" entre les functions\n");
    printf("- Oublie du here_doc avant KEYWORD\n");
    printf("- Oublie du KEYWORD apres here_doc\n");
    printf("==================\n");
}