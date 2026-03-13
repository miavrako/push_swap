/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miavrako <miavrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:46:26 by miavrako          #+#    #+#             */
/*   Updated: 2026/03/13 14:47:55 by miavrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_operation(t_operation *op)
{
	while (op)
	{
		ft_putstr_fd(op->operation, 1);
		write(1, "\n", 1);
		op = op->next;
	}
}
