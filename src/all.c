/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:52:55 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/16 18:22:53 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	terminal(char **argv, int argc, char **env_path, int verbose)
{
	t_env		*env;
	t_command	*cmd;
	char		**argv_cpy;

	env = init_env();
	env->argv_cpy = ft_strcpy_array(argv);
	env->env_path = env_path;
	manage_parsing(env, env->argv_cpy, argc, env_path);
	multi_pipex(env);
	if (verbose == 1)
	{
		cmd = env->first_cmd;
		print_all_cmd(env, cmd);
	}
	free_all(env);
	return (1);
}
