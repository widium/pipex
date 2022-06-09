/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:56:25 by ebennace          #+#    #+#             */
/*   Updated: 2021/10/21 15:56:27 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cont;
	int		i;
	int		a;

	if (!(s1) || !(s2))
		return (NULL);
	i = ft_strlen(s1);
	a = ft_strlen(s2);
	cont = malloc((i + a + 1) * sizeof(char));
	if (!cont)
		return (NULL);
	i = 0;
	a = 0;
	while (s1[i] != '\0')
	{
		cont[i] = s1[i];
		i++;
	}
	while (s2[a] != '\0')
	{
		cont[i + a] = s2[a];
		a++;
	}
	cont[i + a] = '\0';
	return ((char *)cont);
}
/*
int main ()
{
	char s1[] = "12345";
	char s2[] = "12345";
	printf("%s\n",(char *)ft_strjoin(s1, s2));
}
*/
