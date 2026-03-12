/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirarand <mirarand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 07:29:40 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/12 13:41:15 by mirarand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	stack_size(t_stack *stack)
{
	int	n;

	n = 0;
	while (stack)
	{
		n++;
		stack = stack->next;
	}
	return (n);
}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	find_min_index(t_stack *stack)
{
	int	min;
	int	idx;
	int	pos;

	if (!stack)
		return (-1);
	min = stack->content;
	idx = 0;
	pos = 0;
	while (stack)
	{
		if (stack->content < min)
		{
			min = stack->content;
			idx = pos;
		}
		pos++;
		stack = stack->next;
	}
	return (idx);
}

void	assign_indices(t_stack *stack)
{
	t_stack	*node;
	t_stack	*other;
	int		rank;

	node = stack;
	while (node)
	{
		rank = 0;
		other = stack;
		while (other)
		{
			if (other->content < node->content)
				rank++;
			other = other->next;
		}
		node->index = rank;
		node = node->next;
	}
}
