/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miavrako <miavrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:30:59 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/11 14:42:18 by miavrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *counter)
{
	*counter += write(2, &c, 1);
}

void	print_str(const char *str, int *counter)
{
	int	index;

	if (str == NULL)
	{
		print_str(NULL_MESSAGE, counter);
		return ;
	}
	index = 0;
	while (str[index])
	{
		ft_putchar(str[index], counter);
		index++;
	}
}
