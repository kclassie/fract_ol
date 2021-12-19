/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclassie <kclassie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 15:11:16 by kclassie          #+#    #+#             */
/*   Updated: 2021/05/01 23:15:05 by kclassie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	prtarr(int n, int fd)
{
	int	i;
	int	k;
	int	arr[20];

	i = 0;
	k = 0;
	while (n > 0)
	{
		i = n % 10;
		arr[k] = i;
		n = n / 10;
		k++;
	}
	while (k-- > 0)
		ft_putchar_fd(arr[k] + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	if (n < 0 && n > -2147483648)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n < 10 && n >= 0)
		ft_putchar_fd(n + '0', fd);
	if (n > 9)
		prtarr(n, fd);
}
