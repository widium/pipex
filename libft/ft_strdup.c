/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:26:41 by ebennace          #+#    #+#             */
/*   Updated: 2021/10/20 17:26:44 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;

	i = ft_strlen(src);
	i++;
	dest = malloc(i * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, src, i);
	return (dest);
}
/*
int main ()
{
	char src[] = "12345";
	printf("%s\n",ft_strdup(src));
	printf("%s\n",strdup(src));
}
*/
