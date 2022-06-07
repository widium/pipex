/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 10:32:48 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/07 13:30:01 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

void print_char(char *str)
{
	int i = 0;

	while (str[i])
	{
		printf("(%c)\n", str[i]);
		i++;
	}
}

char *remove_n(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		// printf("(%c)\n", str[i]);
		if (str[i] == '\n')
		{
			// printf("Trouver\n");
			str[i] = '\0';
		}
		i++;
	}
	return (str);
}

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

int	str_comp_witout_n(char *first, char *second)
{
	int	i;
	int	size_f;
	int	size_s;
	
	first = remove_n(first);
	
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

int is_first_cmd(t_command *cmd)
{
    if (cmd->index == 1)
        return (1);
    return (0);
}

int is_last_cmd(t_env *env, t_command *cmd)
{
    if (cmd->index == env->nbr_cmd)
        return (1);
    return (0);
}

void close_all(t_env *env)
{
   close(env->in_file->fd);
   close(env->out_file->fd);
   close(env->fd[0]);
   close(env->fd[1]);
   close(env->fd_next[0]);
   close(env->fd_next[1]);   
}