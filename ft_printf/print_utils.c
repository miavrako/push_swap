/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirarand <mirarand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 09:55:21 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/18 11:11:35 by mirarand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex(uintptr_t number, char delimiter, int *counter)
{
	uintptr_t	c;

	if (number >= 16)
		print_hex(number / 16, delimiter, counter);
	c = number % 16;
	if (c < 10)
		c += '0';
	else
		c += delimiter - 10;
	ft_putchar(c, counter);
}

void	print_unsigned(unsigned int number, int *counter)
{
	if (number >= 10)
		print_unsigned(number / 10, counter);
	ft_putchar((number % 10) + '0', counter);
}

void	print_memory(void *add, int *counter)
{
	if (add == NULL)
	{
		print_str("(nil)", counter);
		return ;
	}
	print_str("0x", counter);
	print_hex((uintptr_t)add, 'a', counter);
}

void	print_float(double val, int *counter)
{
	int	decimal;

	ft_putnbr((int)val, counter);
	ft_putchar('.', counter);
	decimal = ((int)(val * 100) % 100);
	ft_putnbr(decimal, counter);
	if (decimal <= 9)
		ft_putchar('0', counter);
}
