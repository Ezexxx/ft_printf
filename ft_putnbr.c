/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlibrin <anlibrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:43:33 by anlibrin          #+#    #+#             */
/*   Updated: 2024/11/22 09:52:48 by anlibrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(int i)
{
	int	count;

	count = 0;
	if (i == 0)
		count++;
	if (i < 0)
		count++;
	while (i != 0)
	{
		i = i / 10;
		count++;
	}
	return (count);
}

int	ft_putnbr(int nb)
{
	int	count;

	count = ft_len(nb);
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		nb = nb * -1;
		ft_putchar('-');
		ft_putnbr(nb);
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar((nb + 48));
	}
	return (count);
}
