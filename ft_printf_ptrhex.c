/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptrhex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlibrin <anlibrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:53:25 by anlibrin          #+#    #+#             */
/*   Updated: 2024/11/26 10:34:38 by anlibrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(unsigned long i)
{
	int	count;

	count = 0;
	if (i == 0)
		count++;
	while (i != 0)
	{
		i = i / 16;
		count++;
	}
	return (count);
}

static void	ft_print_hexa(unsigned long i)
{
	if (i / 16)
		ft_print_hexa(i / 16);
	if (i % 16 < 10)
		ft_putchar(i % 16 + 48);
	else
		ft_putchar(i % 16 + 'a' - 10);
}

int	ft_printf_ptrhex( unsigned long i)
{
	int	count;

	if (!i)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count = 0;
	ft_putstr("0x");
	count = ft_len(i) + 2;
	ft_print_hexa(i);
	return (count);
}
