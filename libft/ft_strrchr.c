/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclassie <kclassie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 20:37:12 by kclassie          #+#    #+#             */
/*   Updated: 2021/05/05 22:49:06 by kclassie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The strrchr() function is identical to strchr(), except it locates
the last occurrence of c. */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*res;

	res = 0;
	len = ft_strlen(s) + 1;
	if (c > 256)
		c = c - 256;
	while (len > 0)
	{
		if (*s == c)
			res = (char *)s;
		s++;
		len--;
	}
	return (res);
}
