/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miavrako <miavrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:46:07 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/11 15:00:19 by miavrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rrotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = ft_lstlast(*stack);
	second_last = *stack;
	while (second_last->next != last)
		second_last = second_last->next;
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_stack **stack_a, t_bench *bench)
{
	ft_rrotate(stack_a);
	ft_putstr_fd("rra\n", 1);
	if (bench->activated)
		bench->rra++;
}

void	rrb(t_stack **stack_b, t_bench *bench)
{
	ft_rrotate(stack_b);
	ft_putstr_fd("rrb\n", 1);
	if (bench->activated)
		bench->rrb++;
}

void	rrr(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	ft_rrotate(stack_a);
	ft_rrotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
	if (bench->activated)
		bench->rrr++;
}
