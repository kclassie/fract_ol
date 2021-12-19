/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclassie <kclassie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 19:55:53 by kclassie          #+#    #+#             */
/*   Updated: 2021/05/07 18:59:35 by kclassie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* fill a byte string with a byte value
The memset() function writes len bytes of value c (converted to an
unsigned char) to the string b.
The memset() function returns its first argument. */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*((unsigned char *)b + i) = c;
		i++;
	}
	if (!b)
		return (NULL);
	return (b);
}
