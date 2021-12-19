/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclassie <kclassie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:29:27 by kclassie          #+#    #+#             */
/*   Updated: 2021/05/07 00:31:30 by kclassie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_res(const char *s, char **str, size_t start, size_t end)
{
	if (s[start] == '\0' || *s == '\0')
	{
		*str = (char *)malloc(sizeof(char) * 1);
		if (!*str)
			return (NULL);
		*str[0] = '\0';
		return (*str);
	}
	*str = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!*str)
		return (NULL);
	ft_strlcpy(*str, &s[start], end - start + 2);
	return (*str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*result;
	char const	*dup;
	size_t		start;
	size_t		end;

	result = NULL;
	dup = s1;
	start = 0;
	end = 0;
	if (*s1 == '\0')
		return (get_res(s1, &result, start, end));
	while (ft_strchr(set, *dup) != NULL && *dup != '\0')
	{
		start++;
		dup++;
	}
	end = ft_strlen(s1);
	dup = &s1[ft_strlen(s1)];
	while (ft_strchr(set, *dup--) != NULL && end > 0)
		end--;
	return (get_res(s1, &result, start, end));
}
