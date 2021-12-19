/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclassie <kclassie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:22:39 by kclassie          #+#    #+#             */
/*   Updated: 2021/05/05 23:59:08 by kclassie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*function locates the first occurrence of the null-terminated string
needle in the string haystack, where not more than len characters are searched.
Characters that appear after a `\0' character are not searched.
If needle is an empty string, haystack is returned; if needle occurs
nowhere in haystack, NULL is returned; otherwise a pointer to the first
character of the first occurrence of needle is returned.*/

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h_len;
	size_t	n_len;
	size_t	i;

	h_len = ft_strlen(haystack);
	n_len = ft_strlen(needle);
	i = 0;
	if (n_len == 0)
		return ((char *)haystack);
	if (n_len > h_len || n_len > len)
		return (NULL);
	while (i <= (h_len - n_len) && i <= (len - n_len))
	{
		if (haystack[i] == needle[0])
		{
			if (!(ft_strncmp(&haystack[i], needle, n_len)))
				return ((char *)(&haystack[i]));
		}
		i++;
	}
	return (NULL);
}
