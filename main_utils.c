/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirarand <mirarand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 09:35:00 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/31 09:19:41 by mirarand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_run(t_stack **a, t_stack **b, t_operation **op, t_run *run)
{
	*a = NULL;
	*b = NULL;
	*op = NULL;
	run->from_split = 0;
}

void	free_args_run(char **args, int from_split)
{
	if (from_split)
		free_split(args);
	else
		free(args);
}
