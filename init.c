/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:54:50 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/06 16:23:20 by ebennace         ###   ########.fr       */
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
	command->next_cmd = NULL;
	command->index = 0;
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
	file->name = NULL;
	file->fd = -1;
	return (file);
}

t_env *init_env(void)
{
	t_env *env;

	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->in_file = init_file();
	env->out_file = init_file();
	env->tmp_file = init_file();
    env->first_cmd = init_command();
    env->path = init_path();
	env->nbr_cmd = 0;
	env->keyword = NULL;
	return (env);
}

