/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lowhex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlibrin <anlibrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:46:30 by anlibrin          #+#    #+#             */
/*   Updated: 2024/11/26 10:33:56 by anlibrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(unsigned int i)
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

int	ft_printf_lowhex(unsigned int i)
{
	int	count;

	count = ft_len(i);
	if (i / 16)
		ft_printf_lowhex(i / 16);
	if (i % 16 < 10)
		ft_putchar(i % 16 + 48);
	else
		ft_putchar(i % 16 + 'a' - 10);
	return (count);
}
