/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirarand <mirarand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 07:58:51 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/17 09:02:10 by mirarand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

static t_stack	*new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		print_error();
	node->content = value;
	node->index = 0;
	node->next = NULL;
	return (node);
}

void	push_back(t_stack **stack, int value)
{
	t_stack	*node;

	node = new_node(value);
	if (!*stack)
	{
		*stack = node;
		return ;
	}
	ft_lstlast(*stack)->next = node;
}

t_stack	*stack_copy(t_stack *src)
{
	t_stack	*copy;

	copy = NULL;
	while (src)
	{
		push_back(&copy, src->content);
		src = src->next;
	}
	return (copy);
}
