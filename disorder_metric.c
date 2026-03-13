/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_metric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miavrako <miavrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 09:14:05 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/13 11:34:52 by miavrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	disorder_metric(t_stack *stack, int size)
{
	t_stack	*node;
	t_stack	*other;
	long	mistakes;
	long	total;

	if (size <= 1)
		return (0.0);
	mistakes = 0;
	total = 0;
	node = stack;
	while (node)
	{
		other = node->next;
		while (other)
		{
			if (node->content > other->content)
				mistakes++;
			other = other->next;
		}
		node = node->next;
	}
	total = (long)size * (size - 1) / 2;
	return (mistakes * 100.0 / total);
}
