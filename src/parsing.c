/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:28:52 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/09 10:23:17 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	manage_parsing(t_env *env, char **argv, int argc, char **env_path)
{
	recover_path(env, env_path);
	check_input(env, argv, argc);
	create_chained_list(env, argv, argc);
	count_cmd(env);
}

void	create_chained_list(t_env *env, char **argv, int argc)
{
	t_command	*cmd;
	t_command	*next_cmd;
	int			i;
	int			index;

	i = env->start;
	index = 1;
	while (i < argc)
	{
		if (i < (env->start + 1))
		{
			cmd = init_command();
			setup_cmd(env, cmd, argv[i], index);
			env->first_cmd = cmd;
		}
		else
		{
			next_cmd = init_command();
			setup_cmd(env, next_cmd, argv[i], index);
			connect_cmd(cmd, next_cmd);
			cmd = next_cmd;
		}
		i++;
		index++;
	}
}

int	check_input(t_env *env, char **argv, int argc)
{
	int	result;

	if (argc <= 3)
		parsing_exit(env);
	result = detect_in_file_or_keyword(env, argv, argc);
	detect_and_create_out_file(env, argv, argc);
	if (result == 2)
	{
		here_doc(env);
		return (1);
	}
	else if (result == 1)
		return (1);
	parsing_exit(env);
}