/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_metric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirarand <mirarand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 09:14:05 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/09 11:38:21 by mirarand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	disorder_metric(t_stack *stack, int size, long *total_out)
{
	t_stack	*node;
	t_stack	*other;
	long	mistakes;
	long	total;

	if (size <= 1)
	{
		*total_out = 1;
		return (0);
	}
	mistakes = 0;
	total = 0;
	node = stack;
	while (node)
	{
		other = node->next;
		while (other)
		{
			total++;
			if (node->content > other->content)
				mistakes++;
			other = other->next;
		}
		node = node->next;
	}
	*total_out = total;
	return (mistakes);
}
