/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:55:45 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/06 14:49:24 by ebennace         ###   ########.fr       */
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
    printf("Name : %s\n", env->file->in);
    printf("Fd : [%d]\n", env->file->fd_in);
    printf("==================\n");
    while (cmd->next_cmd)
    {
        print_cmd(cmd);
        cmd = cmd->next_cmd;
    }
    printf("==================\n");
    printf("Name : %s\n", env->file->out);
    printf("Fd : [%d]\n", env->file->fd_out);
    printf("==================\n");
}

void print_error(void)
{
    printf("========= Error =========\n");
    printf("""Example Input : file_in \"cmd_1\" \"cmd_2\" out_file\n""");
    printf("==================\n");
}