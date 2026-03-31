/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirarand <mirarand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:30:49 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/31 13:31:53 by mirarand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include <limits.h>

static int	is_valid_int(const char *str)
{
	if (!str || !*str)
		return (0);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

static int	process_arg_bonus(t_stack **a, const char *s)
{
	long	v;

	if (!is_valid_int(s))
		return (0);
	v = ft_atol(s);
	if (v < INT_MIN || v > INT_MAX)
		return (0);
	if (!num_duplicate(*a, (int)v))
		return (0);
	push_back(a, (int)v);
	return (1);
}

void	init_stacks_bonus(t_stack **a, t_stack **b, char **args)
{
	int	i;

	*a = NULL;
	*b = NULL;
	i = 0;
	while (args[i])
		if (!process_arg_bonus(a, args[i++]))
			return ;
}

void	cleanup_bonus(t_stack *a, t_stack *b, char **args, int from_split)
{
	free_stack(a);
	free_stack(b);
	if (from_split)
		free_split(args);
	else if (args)
		free(args);
}
