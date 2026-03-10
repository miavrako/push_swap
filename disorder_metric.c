/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_metric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miavrako <miavrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 09:14:05 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/10 12:55:32 by miavrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	disorder_metric(t_stack *stack, int size, long total_out)
		// Modif type long sans *
{
	t_stack *node;
	t_stack *other;
	long mistakes;
	long total;

	if (size <= 1)
	{
		total_out = 1;
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
	total_out = total;
	return (mistakes * 100 / total_out); // Modif calcul return
}
