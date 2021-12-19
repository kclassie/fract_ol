/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclassie <kclassie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 20:03:18 by kclassie          #+#    #+#             */
/*   Updated: 2021/05/05 22:47:41 by kclassie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The strchr() function locates the first occurrence of c (converted to a char)
in the string pointed to by s.  The terminating null character is
considered to be part of the string; therefore if c is `\0', the functions
locate the terminating `\0'.
The functions strchr() and strrchr() return a pointer to the located
character, or NULL if the character does not appear in the string. */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	len;

	if (c > 256)
		c = c - 256;
	len = ft_strlen(s) + 1;
	while (len > 0)
	{
		if (*s == c)
			return ((char *)s);
		s++;
		len--;
	}
	return (0);
}
