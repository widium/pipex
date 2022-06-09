/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:44:40 by ebennace          #+#    #+#             */
/*   Updated: 2021/10/21 17:44:42 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_copie(char *dest, char *s, int i, int len)
{
	int	a;

	a = 0;
	while (a < (int)len)
	{
		dest[a] = s[i];
		i++;
		a++;
	}
	dest[a] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	int		i;
	int		t;

	i = 0;
	if (!s)
		return (NULL);
	t = ft_strlen(s);
	if ((int)start >= t)
		return (ft_strdup(""));
	if (t - start < len)
		len = t - (int)start;
	dest = malloc ((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0 + (int)start;
	return (ft_copie((char *)dest, (char *)s, i, (int)len));
}
/*
int main ()
{
	char s[] = "123456789erhderahqwatghtehyq3TWYHEATJWJ65HY4T3QWRAfgedahetnj5";
	int start = 150;
	int len = 6;
	printf("%s\n",ft_substr(s, start, len));

}
*/
