/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaoloni <fpaoloni@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:13:48 by fpaoloni          #+#    #+#             */
/*   Updated: 2023/03/03 17:28:38 by fpaoloni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	format_sorting(char flag, va_list curr_param);
int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putnbr_di(int n, char type);
int	ft_putnbr_uxp(unsigned long long n, char type);
int	ft_putnbr_base(unsigned long long n, int base, char type);
int	ft_num_length_signed(long long n);
int	ft_num_length_unsigned(unsigned long long n, char type);

#endif
