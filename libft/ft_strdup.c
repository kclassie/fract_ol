/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclassie <kclassie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 22:16:32 by kclassie          #+#    #+#             */
/*   Updated: 2021/05/03 13:17:43 by kclassie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The strdup() function allocates sufficient memory for a copy of the
string s1, does the copy, and returns a pointer to it.  The pointer may
subsequently be used as an argument to the function free(3).

If insufficient memory is available, NULL is returned and errno is set t*/

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	buf;

	buf = sizeof(char) * (ft_strlen(s1) + 1);
	s2 = malloc(buf);
	if (s2)
		ft_memcpy(s2, s1, buf);
	return (s2);
}
