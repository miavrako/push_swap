/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miavrako <miavrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 08:11:14 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/09 22:19:02 by miavrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}					t_stack;

t_stack		*ft_lstlast(t_stack *lst);
int			stack_size(t_stack *stack);
int			find_min_index(t_stack *stack);
void		assign_indices(t_stack *stack);
void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_a, t_stack **stack_b);
void		ra(t_stack **stack_a);
void		rra(t_stack **stack_a);
void		sa(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rrb(t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);
void		sb(t_stack **stack_b);
void		ss(t_stack **stack_a, t_stack **stack_b);
void		sort_two(t_stack **a, t_stack **b);
void		sort_three(t_stack **a, t_stack **b);
void		sort_five(t_stack **a, t_stack **b);
void		algo_complex(t_stack **a, t_stack **b);
void		ft_putstr_fd(char *s, int fd);
long		disorder_metric(t_stack *stack, int size, long *total_out);
void		algo_adaptive(t_stack **a, t_stack **b);
void		algo_simple(t_stack **stack_a, t_stack **stack_b);
void		algo_medium(t_stack **stack_a, t_stack **stack_b);
void		algo_flag(t_stack **a, t_stack **b, char *flag);

#endif
