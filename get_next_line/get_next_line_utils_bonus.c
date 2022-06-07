/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:37:26 by ebennace          #+#    #+#             */
/*   Updated: 2021/12/07 15:39:23 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strlcpy(char *dest, const char *src, int n)
{
	int	srcsize;
	int	i;

	n = (unsigned int)n;
	i = 0;
	srcsize = ft_strlen((char *)src);
	if (n)
	{
		while (src[i] != '\0' && (i + 1 < n))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = 0;
	}
	return (srcsize);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;
	int		r;

	i = ft_strlen(src);
	i++;
	dest = malloc(i * sizeof(char));
	if (!dest)
		return (NULL);
	r = ft_strlcpy(dest, src, i);
	if (r == i)
		return (dest);
	return (NULL);
}

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

char	*ft_substr(char const *s, int start, int len)
{
	char	*res;
	int		i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s[start];
		start++;
		i++;
	}
	res[i] = '\0';
	return (res);
}
