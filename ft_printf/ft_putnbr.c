/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miavrako <miavrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 09:49:33 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/13 11:49:02 by miavrako         ###   ########.fr       */
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
