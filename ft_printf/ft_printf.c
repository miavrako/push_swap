/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miavrako <miavrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 09:39:04 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/13 12:04:01 by miavrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_arg(const char *str, va_list *arg, int index, int *counter)
{
	if (str[index] == 'c')
		ft_putchar(va_arg(*arg, int), counter);
	else if (str[index] == 's')
		print_str(va_arg(*arg, char *), counter);
	else if (str[index] == 'p')
		print_memory(va_arg(*arg, void *), counter);
	else if (str[index] == 'd' || str[index] == 'i')
		ft_putnbr(va_arg(*arg, int), counter);
	else if (str[index] == 'u')
		print_unsigned(va_arg(*arg, unsigned int), counter);
	else if (str[index] == 'x')
		print_hex(va_arg(*arg, unsigned int), 'a', counter);
	else if (str[index] == 'X')
		print_hex(va_arg(*arg, unsigned int), 'A', counter);
	else if (str[index] == '%')
		ft_putchar(str[index], counter);
	else if (str[index] == 'f')
		print_float(va_arg(*arg, double), counter);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		index;
	int		counter;

	va_start(arg, str);
	index = 0;
	counter = 0;
	if (!str)
		return (-1);
	while (str[index])
	{
		if (str[index] == '%')
		{
			index++;
			print_arg(str, &arg, index, &counter);
			index++;
		}
		else
			ft_putchar(str[index++], &counter);
	}
	va_end(arg);
	return (counter);
}
