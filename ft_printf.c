/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlibrin <anlibrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:10:32 by anlibrin          #+#    #+#             */
/*   Updated: 2024/11/28 09:51:02 by anlibrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

static int	ft_print(const char *prefix, va_list list)
{
	int	count;

	count = 0;
	if (*prefix == 'c')
		count = ft_putchar(va_arg(list, int));
	else if (*prefix == 's')
		count = ft_putstr(va_arg(list, char *));
	else if (*prefix == 'i' || *prefix == 'd')
		count = ft_putnbr(va_arg(list, int));
	else if (*prefix == 'u')
		count = ft_unsputnbr(va_arg(list, unsigned int));
	else if (*prefix == 'p')
		count = ft_printf_ptrhex((unsigned long)va_arg(list, void *));
	else if (*prefix == 'x')
		count = ft_printf_lowhex(va_arg(list, unsigned int));
	else if (*prefix == 'X')
		count = ft_printf_apphex(va_arg(list, unsigned int));
	else if (*prefix == '%')
		count = write(1, "%", 1);
	else
		count = ft_putstr((char *)prefix - 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	list;

	count = 0;
	if (!format)
		return (-1);
	va_start(list, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1) == '\0')
			return (-1);
		if (*format == '%')
		{
			format++;
			count += ft_print(format, list);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(list);
	return (count);
}