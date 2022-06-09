/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 10:32:48 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/09 10:15:39 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	same_str(char *first, char *second)
{
	int	i;
	int	size_f;
	int	size_s;

	size_f = ft_strlen(first);
	size_s = ft_strlen(second);
	if (size_s != size_f)
		return (0);
	i = 0;
	while (first[i] && second[i])
	{
		if (first[i] != second[i])
			return (0);
		++i;
	}
	return (1);
}

int	is_first_cmd(t_command *cmd)
{
	if (cmd->index == 1)
		return (1);
	return (0);
}

int	is_last_cmd(t_env *env, t_command *cmd)
{
	if (cmd->index == env->nbr_cmd)
		return (1);
	return (0);
}
