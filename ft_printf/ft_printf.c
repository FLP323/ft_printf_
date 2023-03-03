/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaoloni <fpaoloni@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:09:32 by fpaoloni          #+#    #+#             */
/*   Updated: 2023/03/03 15:27:20 by fpaoloni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_sorting(char flag, va_list curr_param)
{
	if (flag == 'c')
		return (ft_putchar(va_arg(curr_param, int)));
	else if (flag == 's')
		return (ft_putstr(va_arg(curr_param, char *)));
	else if (flag == 'd')
		return (ft_putnbr_di(va_arg(curr_param, int), 'd'));
	else if (flag == 'i')
		return (ft_putnbr_di(va_arg(curr_param, int), 'i'));
	else if (flag == 'u')
		return (ft_putnbr_uxp(va_arg(curr_param, unsigned int), 'u'));
	else if (flag == 'x')
		return (ft_putnbr_uxp(va_arg(curr_param, unsigned int), 'x'));
	else if (flag == 'X')
		return (ft_putnbr_uxp(va_arg(curr_param, unsigned int), 'X'));
	else if (flag == 'p')
		return (ft_putnbr_uxp(va_arg(curr_param, unsigned long long), 'p'));
	else if (flag == '%')
	{
		ft_putchar('%');
		return (1);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		counter;

	va_start (args, format);
	i = 0;
	counter = 0;
	while (format[i])
	{
		if (!format[i])
			return (counter);
		if (format[i] != '%')
		{
			counter++;
			ft_putchar(format[i]);
			i++;
		}
		if (format[i] == '%')
		{
			counter += format_sorting(format[++i], args);
			i++;
		}
	}
	return (counter);
}
