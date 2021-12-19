/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclassie <kclassie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 15:27:07 by kclassie          #+#    #+#             */
/*   Updated: 2021/05/05 22:49:28 by kclassie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*locate byte in byte string The memchr() function locates
the first occurrence of c (converted to an unsigned char) in string s.
The memchr() function returns a pointer to the byte located, or NULL if
no such byte exists within n bytes.*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str;

	if (c > 256)
		c = c - 256;
	if (n != 0)
		str = (char *)s;
	while (n != 0)
	{
		if (*str++ == c)
			return ((void *)str - 1);
		n--;
	}
	return (NULL);
}
