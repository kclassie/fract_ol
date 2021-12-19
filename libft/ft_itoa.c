/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclassie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 21:02:27 by kclassie          #+#    #+#             */
/*   Updated: 2021/09/29 21:05:43 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	if (n == 0)
		len = 1;
	while (n >= 1 || n <= -1)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	num;

	num = n;
	len = get_len(n);
	str = malloc(sizeof(char) * len + 1);
	if (str)
	{
		if (n < 0)
			num = -num;
		str[len] = '\0';
		len--;
		while (len >= 0)
		{
			str[len] = (num % 10) + '0';
			num = num / 10;
			len--;
		}
		if (n < 0)
			str[0] = '-';
	}
	return (str);
}
