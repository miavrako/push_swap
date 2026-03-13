/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miavrako <miavrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:24:23 by miavrako          #+#    #+#             */
/*   Updated: 2026/03/13 09:18:08 by miavrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_operation(t_program *program, char *operation)
{
	t_operation	*new;
	t_operation	*temp;

	if (!program)
		return ;
	new = malloc(sizeof(t_operation));
	if (!new)
		return ;
	new->operation = operation;
	new->next = NULL;
	if (!program->op)
		program->op = new;
	else
	{
		temp = program->op;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	program->op_count++;
}
