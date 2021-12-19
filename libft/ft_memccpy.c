/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclassie <kclassie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 18:31:46 by kclassie          #+#    #+#             */
/*   Updated: 2021/04/25 18:29:20 by kclassie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* copy string until character found
The memccpy() function copies bytes from string src to string dst. If
the character c (as converted to an unsigned char) occurs in the string
src, the copy stops and a pointer to the byte after the copy of c in the
string dst is returned.  Otherwise, n bytes are copied, and a NULL
pointer is returned.
The source and destination strings should not overlap, as the behavior
is undefined.
*/

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	const char		*s;
	size_t			i;

	d = 0;
	s = 0;
	i = 0;
	if (n != 0)
	{
		d = (unsigned char *)dst;
		s = (char *)src;
	}
	while (n != 0)
	{
		*(d + i) = *(s + i);
		if (*(d + i) == ((unsigned char)c))
			return (d + i + 1);
		n--;
		i++;
	}
	return (NULL);
}
