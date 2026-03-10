/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirarand <mirarand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 09:49:33 by mirarand          #+#    #+#             */
/*   Updated: 2026/02/19 13:33:51 by mirarand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int number, int *counter)
{
	if (number == INT_MIN)
	{
		print_str("-2147483648", counter);
		return ;
	}
	if (number < 0)
	{
		ft_putchar('-', counter);
		number = -number;
	}
	if (number >= 10)
		ft_putnbr(number / 10, counter);
	ft_putchar((number % 10) + '0', counter);
}
