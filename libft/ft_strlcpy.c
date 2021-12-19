/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclassie <kclassie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:34:05 by kclassie          #+#    #+#             */
/*   Updated: 2021/04/30 19:28:03 by kclassie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*size-bounded string copying

strlcpy() take the full size of the destination buffer and
guarantee NUL-termination if there is room.  Note that room for the NUL
should be included in dstsize.

strlcpy() copies up to dstsize - 1 characters from the string src to dst,
NUL-terminating the result if dstsize is not 0. */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!(dst == NULL || src == NULL))
	{
		if (dstsize != 0)
		{
			while (i < (dstsize - 1) && src[i] != '\0')
			{
				dst[i] = src[i];
				i++;
			}
			dst[i] = '\0';
		}
		return (ft_strlen(src));
	}
	return (0);
}
