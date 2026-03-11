/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miavrako <miavrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:46:11 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/11 14:57:06 by miavrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_stack **stack_a, t_bench *bench)
{
	ft_swap(stack_a);
	ft_putstr_fd("sa\n", 1);
	if (bench->activated)
		bench->sa++;
}

void	sb(t_stack **stack_b, t_bench *bench)
{
	ft_swap(stack_b);
	ft_putstr_fd("sb\n", 1);
	if (bench->activated)
		bench->sb++;
}

void	ss(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_putstr_fd("ss\n", 1);
	if (bench->activated)
		bench->ss++;
}
