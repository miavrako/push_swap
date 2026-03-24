/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miavrako <miavrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 22:27:03 by miavrako          #+#    #+#             */
/*   Updated: 2026/03/24 11:52:05 by miavrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

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

int	num_duplicate(t_stack *stack, int value)
{
	while (stack)
	{
		if ((stack)->content == value)
			return (0);
		stack = (stack)->next;
	}
	return (1);
}

void	stack_a_valid(t_stack **stack_a, char **argv)
{
	long long	num;
	int			i;

	i = 0;
	while (argv[i])
	{
		if (!is_valid_int(argv[i]))
			print_error();
		num = ft_atol(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
			print_error();
		if (!num_duplicate(*stack_a, num))
			print_error();
		push_back(stack_a, (int)num);
		i++;
	}
}
