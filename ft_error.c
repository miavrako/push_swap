/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miavrako <miavrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 22:27:03 by miavrako          #+#    #+#             */
/*   Updated: 2026/03/10 22:17:04 by miavrako         ###   ########.fr       */
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

long	no_long_num(const char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	if (!*str)
		print_error();
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			print_error();
		res = res * 10 + (*str - '0');
		if ((sign * res) < INT_MIN || (sign * res) > INT_MAX)
			print_error();
		str++;
	}
	return (sign * res);
}

void	no_duplicate(t_stack **stack)
{
	t_stack	*node;
	t_stack	*other;

	node = *stack;
	while (node)
	{
		other = node->next;
		while (other)
		{
			if (node->content == other->content)
				print_error();
			other = other->next;
		}
		node = node->next;
	}
}
