/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_ops_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirarand <mirarand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:44:05 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/12 15:16:46 by mirarand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	apply_swap(char *line, t_stack **a, t_stack **b)
{
	if (ft_strcmp(line, "sa") == 0)
		ft_swap_hide(a);
	else if (ft_strcmp(line, "sb") == 0)
		ft_swap_hide(b);
	else if (ft_strcmp(line, "ss") == 0)
	{
		ft_swap_hide(a);
		ft_swap_hide(b);
	}
	else
		return (0);
	return (1);
}

int	apply_push(char *line, t_stack **a, t_stack **b)
{
	if (ft_strcmp(line, "pa") == 0)
		ft_push_hide(b, a);
	else if (ft_strcmp(line, "pb") == 0)
		ft_push_hide(a, b);
	else
		return (0);
	return (1);
}
