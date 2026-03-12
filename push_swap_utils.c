/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirarand <mirarand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 19:09:39 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/12 10:02:45 by mirarand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	algo_flag(t_stack **a, t_stack **b, char *flag)
{
	if (ft_strcmp(flag, "--simple") == 0)
		algo_simple(a, b);
	else if (ft_strcmp(flag, "--medium") == 0)
		algo_medium(a, b);
	else if (ft_strcmp(flag, "--complex") == 0)
		algo_complex(a, b);
	else
		algo_adaptive(a, b);
}
