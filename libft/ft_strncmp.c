/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 17:58:19 by ebennace          #+#    #+#             */
/*   Updated: 2021/10/17 17:58:21 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *first, const char *second, size_t size)
{
	int	i;

	i = 0;
	if ((int)size < 0)
		size = ft_strlen(first);
	while ((unsigned char)(first[i]) != '\0'
	&& (unsigned char)(second[i]) != '\0' && i < (int)size)
	{
		if ((unsigned char)(first[i]) != (unsigned char)(second[i]))
			return ((unsigned char)first[i] - (unsigned char)second[i]);
		i++;
	}
	if (i != (int)size)
		return ((unsigned char)first[i] - (unsigned char)second[i]);
	return ((unsigned char)first[i - 1] - (unsigned char)second[i - 1]);
}
/*
int main ()
{
	char first[] = "1234";
	char second[] = "1236";
	size_t n = -1;
	printf("%i\n",ft_strncmp(first,second,n));
	printf("%i\n",strncmp(first,second,n));

}
*/
