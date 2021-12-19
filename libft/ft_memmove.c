/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclassie <kclassie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:46:26 by kclassie          #+#    #+#             */
/*   Updated: 2021/04/25 13:44:50 by kclassie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*copy byte string
The memmove() function copies len bytes from string src to string dst.
The two strings may overlap; the copy is always done in a non-destructive manner.
The memmove() function returns the original value of dst.*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;
	unsigned char		*ltd;
	const unsigned char	*lts;

	d = dst;
	s = src;
	ltd = d + (len - 1);
	lts = s + (len - 1);
	if (d == s)
		return (dst);
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		while (len--)
			*ltd-- = *lts--;
	}
	return (dst);
}
