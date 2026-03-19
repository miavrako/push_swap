/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miavrako <miavrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 07:57:32 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/19 14:44:57 by miavrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_operations(t_operation *ops, t_program *s)
{
	while (ops)
	{
		if (!ft_strcmp(ops->operation, "sa"))
			s->sa++;
		else if (!ft_strcmp(ops->operation, "sb"))
			s->sb++;
		else if (!ft_strcmp(ops->operation, "ss"))
			s->ss++;
		else if (!ft_strcmp(ops->operation, "pa"))
			s->pa++;
		else if (!ft_strcmp(ops->operation, "pb"))
			s->pb++;
		ops = ops->next;
	}
}

void	count_operations2(t_operation *ops, t_program *s)
{
	while (ops)
	{
		if (!ft_strcmp(ops->operation, "ra"))
			s->ra++;
		else if (!ft_strcmp(ops->operation, "rb"))
			s->rb++;
		else if (!ft_strcmp(ops->operation, "rr"))
			s->rr++;
		else if (!ft_strcmp(ops->operation, "rra"))
			s->rra++;
		else if (!ft_strcmp(ops->operation, "rrb"))
			s->rrb++;
		else if (!ft_strcmp(ops->operation, "rrr"))
			s->rrr++;
		ops = ops->next;
	}
}
