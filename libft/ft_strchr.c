/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:15:29 by ebennace          #+#    #+#             */
/*   Updated: 2021/10/13 19:15:31 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != (char) c)
	{
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)(str + i));
	return (NULL);
}

/*int main ()
{
	int c = 's';
	const char *str = "test";
	printf("%s",ft_strchr(str, c));
}
*/
