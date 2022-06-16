/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:24:14 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/16 18:34:07 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	here_doc(t_env *env)
{
	char	*line;
	char	*name;
	int		fd;

	create_tmp_file(env);
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!ft_strncmp(env->keyword, line, (ft_strlen(env->keyword))))
		{
			free(line);
			break ;
		}
		else
		{
			ft_putstr_fd(line, env->tmp_file->fd);
			free(line);
		}
	}
	close_and_save_tmp_file(env);
}

void	create_tmp_file(t_env *env)
{
	char	*name;
	int		fd;

	name = "tempo.txt";
	env->tmp_file->name = name;
	fd = open(name, O_CREAT | O_WRONLY, 0777);
	env->tmp_file->fd = fd;
	if (env->tmp_file->fd == -1)
		parsing_exit(env);
}

void	close_and_save_tmp_file(t_env *env)
{
	int	fd;

	close(env->tmp_file->fd);
	fd = open(env->tmp_file->name, O_RDONLY);
	env->in_file->fd = fd;
	env->in_file->name = NULL;
	unlink(env->tmp_file->name);
	if (fd == -1)
		parsing_exit(env);
	free(env->tmp_file);
}

int	detect_in_file_or_keyword(t_env *env, char **argv, int argc)
{
	char	*line;

	if (same_str(argv[1], "here_doc"))
	{
		if (argc == 4)
			parsing_exit(env);
		env->keyword = argv[2];
		env->start = 3;
		return (2);
	}
	else
	{
		env->in_file->name = ft_strcpy(argv[1]);
		env->in_file->fd = open(env->in_file->name, O_RDONLY, 0777);
		env->start = 2;
		if (env->in_file->fd == -1)
			parsing_exit(env);
	}
	return (1);
}

void	detect_and_create_out_file(t_env *env, char **argv, int argc)
{
	env->out_file->name = ft_strcpy(argv[argc - 1]);
	env->out_file->fd = open(env->out_file->name,
			O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (env->out_file->fd == -1)
		parsing_exit(env);
}
