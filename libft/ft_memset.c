/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:03:41 by ebennace          #+#    #+#             */
/*   Updated: 2021/10/14 13:03:43 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	int	i;

	i = 0;
	while (i < (int)n)
	{
		*(unsigned char *)(str + i) = c;
		i++;
	}
	return (str);
}

/*int main ()
{
	char str[100] = "This is string.h library function";
	int c = '$';
	size_t n = 7;
	printf("%s",ft_memset(str, c ,n));
}
*/
