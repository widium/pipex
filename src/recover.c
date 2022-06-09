/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recover.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:40:59 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/08 11:52:06 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*start_with(char *str, char *start)
{
	int		i;
	char	*result;

	result = ft_strnstr(str, start, ft_strlen(str));
	if (result != str)
		return (NULL);
	return (result);
}

void	recover_path(t_env *env, char **env_path)
{
	int	i;

	i = -1;
	while (env_path[++i])
	{
		if (start_with(env_path[i], "PATH=") != NULL)
			env->path->all_path = start_with(env_path[i], "PATH=");
	}
	env->path->list_of_path = ft_split(&env->path->all_path[5], ':');
}
