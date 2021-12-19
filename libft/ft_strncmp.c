/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclassie <kclassie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:03:26 by kclassie          #+#    #+#             */
/*   Updated: 2021/04/27 18:40:00 by kclassie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The strncmp() function compares not more than n characters.  Because
strncmp() is designed for comparing strings rather than binary data,
 characters that appear after a `\0' character are not compared.

functions return an integer greater than, equal to, or less than 0,
according as the string s1 is greater than, equal to,
or less than the string s2.  The comparison is done using
unsigned characters, so that `\200' is greater than `\0'.*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*first;
	unsigned char	*second;

	first = (unsigned char *)s1;
	second = (unsigned char *)s2;
	while (n-- > 0)
	{
		if (*first != *second)
			return (*first - *second);
		if (*first == '\0' || *second == '\0')
			return (0);
		first++;
		second++;
	}
	return (0);
}
