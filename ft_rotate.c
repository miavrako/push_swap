/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miavrako <miavrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:46:03 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/11 14:56:01 by miavrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = ft_lstlast(*stack);
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_stack **stack_a, t_bench *bench)
{
	ft_rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
	if (bench->activated)
		bench->ra++;
}

void	rb(t_stack **stack_b, t_bench *bench)
{
	ft_rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
	if (bench->activated)
		bench->rb++;
}

void	rr(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
	if (bench->activated)
		bench->rr++;
}
