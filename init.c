/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:54:50 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/25 11:18:59 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

t_command   *init_command(void)
{
	t_command	*command;

    command = (t_command *)malloc(sizeof(t_command));
	if (!command)
		return (NULL);
	command->brut = NULL;
	command->bin = NULL;
    command->flags = NULL;
    command->complete = malloc(sizeof(char *) * 2);
	return (command);
}

t_path  *init_path(void)
{
	t_path	*path;

    path = (t_path *)malloc(sizeof(t_path));
	if (!path)
		return (NULL);
	path->all_path = NULL;
    path->path = NULL;
    path->path_bin = NULL;
	return (path);
}

t_file *init_file(void)
{
	t_file *file;

	file = (t_file *)malloc(sizeof(t_file));
	if (!file)
		return (NULL);
	file->in = NULL;
    file->out = NULL;
    file->fd_in = 0;
	file->fd_out = 0;
	return (file);
}

t_env *init_env(void)
{
	t_env *env;

	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->file = init_file();
    env->in_command = init_command();
	env->out_command = init_command();
    env->path = init_path();
	return (env);
}

