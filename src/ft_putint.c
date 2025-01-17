/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:27:23 by hal-moug          #+#    #+#             */
/*   Updated: 2025/01/17 15:51:23 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	size_of_int(int n)
{
	if (n / 10 == 0)
		return (1);
	else
		return (1 + size_of_int(n / 10));
}

void	ft_putnbr_int(int n)
{
	char	c;

	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		ft_putnbr_int(n);
	}
	else
	{
		if (n / 10 == 0)
		{
			c = n + '0';
			write(1, &c, 1);
		}
		else
		{
			c = n % 10 + '0';
			ft_putnbr_int(n / 10);
			write(1, &c, 1);
		}
	}
}

int	print_int(int n)
{
	ft_putnbr_int(n);
	if (n >= 0)
		return (size_of_int(n));
	else
		return (size_of_int(n) + 1);
}
