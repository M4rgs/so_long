/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexaB.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamounir <tamounir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:28:41 by hal-moug          #+#    #+#             */
/*   Updated: 2025/01/17 15:51:41 by tamounir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	print_hexa_helperb(unsigned int n)
{
	char	*s;
	int		c;

	s = "0123456789ABCDEF";
	if (n == 0)
		return ;
	else
	{
		c = n % 16;
		print_hexa_helperb(n / 16);
		write(1, &s[c], 1);
	}
}

int	count_hexab(unsigned int n)
{
	if (n == 0)
		return (0);
	else
		return (1 + count_hexab(n / 16));
}

int	print_hexab(unsigned int n)
{
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	print_hexa_helperb(n);
	return (count_hexab(n));
}
