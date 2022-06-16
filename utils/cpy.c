/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <ebennace@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:22:31 by ebennace          #+#    #+#             */
/*   Updated: 2022/06/16 18:23:33 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strcpy(char *ori)
{
	size_t	i;
	char	*str;

	str = malloc(sizeof(char) * (ft_strlen(ori) + 1));
	i = 0;
	while (ori[i])
	{
		str[i] = ori[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	**ft_strcpy_array(char **ori)
{
	size_t	i;
	size_t	len;
	char	**array;

	len = col_count(ori);
	array = malloc(sizeof(char *) * (len + 1));
	i = 0;
	while (ori[i])
	{
		array[i] = ft_strcpy(ori[i]);
		i++;
	}
	array[i] = 0;
	return (array);
}

size_t	col_count(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
