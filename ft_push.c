/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miavrako <miavrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:45:56 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/11 15:00:19 by miavrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
}

void	pa(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	ft_push(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
	if (bench->activated)
		bench->pa++;
}

void	pb(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	ft_push(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
	if (bench->activated)
		bench->pb++;
}
