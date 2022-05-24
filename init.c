/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:54:50 by ebennace          #+#    #+#             */
/*   Updated: 2022/05/24 14:17:14 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

t_command   *init_command(void)
{
	t_command	*command;

    command = (t_command *)malloc(sizeof(t_command));
	if (!command)
		return (NULL);
	command->bin = NULL;
    command->flags = NULL;
    command->command = malloc(sizeof(char *) * 2);
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
