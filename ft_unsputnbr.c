/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsputnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlibrin <anlibrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:40:21 by anlibrin          #+#    #+#             */
/*   Updated: 2024/11/26 10:33:15 by anlibrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(unsigned int i)
{
	int	count;

	count = 0;
	if (i <= 0)
		count++;
	while (i != 0)
	{
		i = i / 10;
		count++;
	}
	return (count);
}

int	ft_unsputnbr(unsigned int nb)
{
	int	count;

	count = ft_len(nb);
	if (nb >= 10)
	{
		ft_unsputnbr(nb / 10);
		ft_unsputnbr(nb % 10);
	}
	else
		ft_putchar((nb + 48));
	return (count);
}
