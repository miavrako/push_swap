/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirarand <mirarand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:04:22 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/31 13:33:39 by mirarand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "push_swap.h"

void					ft_swap_hide(t_stack **stack);
void					ft_push_hide(t_stack **src, t_stack **dest);
void					ft_rotate_hide(t_stack **stack);
void					ft_rrotate_hide(t_stack **stack);
int						read_and_apply(t_stack **a, t_stack **b);
int						apply_push(char *line, t_stack **a, t_stack **b);
int						apply_swap(char *line, t_stack **a, t_stack **b);
int						apply_rrotate(char *line, t_stack **a, t_stack **b);
int						apply_rotate(char *line, t_stack **a, t_stack **b);
void					free_split(char **split);
char					**build_args_bonus(int argc, char **argv,
							int *from_split);
void					init_stacks_bonus(t_stack **a, t_stack **b,
							char **args);
void					cleanup_bonus(t_stack *a, t_stack *b, char **args,
							int from_split);

#endif
