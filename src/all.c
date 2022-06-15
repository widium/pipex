/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:52:55 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/15 11:22:45 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	terminal(char **argv, int argc, char **env_path, int verbose)
{
	t_env		*env;
	t_command	*cmd;
	char		**argv_cpy;

	env = init_env();
	argv_cpy = ft_strcpy_array(argv);
	env->env_path = env_path;
	manage_parsing(env, argv_cpy, argc, env_path);
	free_array(argv_cpy);
	multi_pipex(env);
	if (verbose == 1)
	{
		cmd = env->first_cmd;
		print_all_cmd(env, cmd);
	}
	free_all(env);
	return (1);
}



char *ft_strcpy(char *ori)
{
	size_t	i;
	char	*str;

	str = malloc(sizeof(char) * ( ft_strlen(ori) + 1));
	i = 0;
	while(ori[i])
	{
		str[i] = ori[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char **ft_strcpy_array(char **ori)
{
	size_t	i;
	size_t	len;
	char	**array;

	len = col_count(ori);
	array = malloc(sizeof(char *) * (len + 1));
	i = 0;
	while(ori[i])
	{
		array[i] = ft_strcpy(ori[i]);
		i++;
	}
	array[i] = 0;
	return (array);
}

size_t col_count(char **str)
{
	size_t i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}