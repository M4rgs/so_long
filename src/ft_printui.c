/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:28:17 by hal-moug          #+#    #+#             */
/*   Updated: 2025/01/17 15:51:34 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	size_of_ui(unsigned int n)
{
	if (n / 10 == 0)
		return (1);
	else
		return (1 + size_of_ui(n / 10));
}

void	ft_putnbr_ui(unsigned int n)
{
	char	c;

	if (n / 10 == 0)
	{
		c = n + '0';
		write(1, &c, 1);
	}
	else
	{
		c = n % 10 + '0';
		ft_putnbr_ui(n / 10);
		write(1, &c, 1);
	}
}

int	print_ui(unsigned int n)
{
	ft_putnbr_ui(n);
	return (size_of_ui(n));
}
