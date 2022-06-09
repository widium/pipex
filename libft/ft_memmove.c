/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennace <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:19:42 by ebennace          #+#    #+#             */
/*   Updated: 2021/10/14 14:19:45 by ebennace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*destcopy;
	const unsigned char	*srccopy;

	destcopy = (unsigned char *)dest;
	srccopy = (const unsigned char *)src;
	if (dest == src)
		return (dest);
	if (srccopy < destcopy)
	{
		while (n != 0)
		{
			n--;
			*(destcopy + n) = *(srccopy + n);
		}
		return (dest);
	}
	while (n != 0)
	{
		n--;
		*destcopy++ = *srccopy++;
	}
	return (dest);
}

/*int main()
{
        unsigned char d[] = "gvedgfefqezfzefe";
        const unsigned char s[] = "Salutest";
        printf("%c\n",(char)ft_memmove(d, s, 7));
}
*/
