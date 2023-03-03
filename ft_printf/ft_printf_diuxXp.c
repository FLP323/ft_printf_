/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_diuxXp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaoloni <fpaoloni@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:16:58 by fpaoloni          #+#    #+#             */
/*   Updated: 2023/03/03 17:15:36 by fpaoloni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_di(int n, char type)
{
	long long	temp;

	temp = n;
	if (n == -2147483648)
	{
		write(1, "-2", 2);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_di(n / 10, type);
	ft_putchar(n % 10 + '0');
	return (ft_num_length_signed(temp));
}

int	ft_putnbr_uxp(unsigned long long n, char type)
{
	if (type == 'p')
	{
		ft_putstr("0x");
		if (n == 0)
		{
			ft_putchar('0');
			return (3);
		}
		ft_putnbr_base(n, 16, 'x');
	}
	else if (type == 'u')
	{
		ft_putnbr_base(n, 10, type);
	}
	else
	{
		ft_putnbr_base(n, 16, type);
	}
	return (ft_num_length_unsigned(n, type));
}

int	ft_putnbr_base(unsigned long long n, int base, char type)
{
	if (n >= (unsigned long long)base)
	{
		ft_putnbr_base(n / base, base, type);
		ft_putnbr_base(n % base, base, type);
	}
	else
	{
		if (n < 10)
			ft_putchar(n + '0');
		else if (type == 'u')
			ft_putchar(n % 10 + '0');
		else if (type == 'x')
			ft_putchar(n % 10 + 'a');
		else
			ft_putchar(n % 10 + 'A');
	}
	if (base == 10)
		return (ft_num_length_signed(n));
	else
		return (ft_num_length_unsigned(n, type));
}

int	ft_num_length_signed(long long n)
{
	int	length;
	int	base;

	length = 0;
	base = 10;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		if (n < 0)
		{
			n = -n;
			length++;
		}
		n /= base;
		length++;
	}
	return (length);
}

int	ft_num_length_unsigned(unsigned long long n, char type)
{
	int	length;
	int	base;

	length = 0;
	if (type == 'u')
		base = 10;
	else
		base = 16;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= base;
		length++;
	}
	if (type == 'p')
		length += 2;
	return (length);
}
