/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olfhal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 14:48:18 by olfhal            #+#    #+#             */
/*   Updated: 2026/03/02 14:48:20 by olfhal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(long long n, int *count)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		(*count)++;
		if (n <= -10)
		{
			ft_putnbr(-(n / 10), count);
		}
		c = '0' - (n % 10);
		write(1, &c, 1);
		(*count)++;
		return ;
	}
	if (n > 9)
		ft_putnbr(n / 10, count);
	c = (n % 10) + '0';
	write(1, &c, 1);
	(*count)++;
}
