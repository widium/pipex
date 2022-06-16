/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:20:56 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/16 18:43:13 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	error_exit(t_env *env, int index)
{
	fprintf(stderr, "---- Exit number : [%d] ----\n", index);
	ft_putstr_fd("Error :\n", STDERR_FILENO);
	ft_putstr_fd("- Fork Fail\n", STDERR_FILENO);
	ft_putstr_fd("- Pipe Fail\n", STDERR_FILENO);
	ft_putstr_fd("- dup2 Fail\n", STDERR_FILENO);
	ft_putstr_fd("- execv Fail\n", STDERR_FILENO);
	free_all(env);
	exit(0);
}

void	parsing_exit(t_env *env)
{
	print_error();
	free_all(env);
	exit(0);
}

void	malloc_exit(void)
{
	ft_putstr_fd("Malloc Fail\n", 1);
	exit(0);
}
