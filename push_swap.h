/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirarand <mirarand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 08:11:14 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/10 14:59:09 by mirarand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}					t_stack;

t_stack				*ft_lstlast(t_stack *lst);
int					stack_size(t_stack *stack);
int					find_min_index(t_stack *stack);
void				assign_indices(t_stack *stack);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack_a);
void				rra(t_stack **stack_a);
void				sa(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rrb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				sort_two(t_stack **a, t_stack **b);
void				sort_three(t_stack **a, t_stack **b);
void				sort_five(t_stack **a, t_stack **b);
void				algo_complex(t_stack **a, t_stack **b);
void				ft_putstr_fd(char *s, int fd);
long				disorder_metric(t_stack *stack, int size, long *total_out);
void				algo_adaptive(t_stack **a, t_stack **b);
void				algo_simple(t_stack **stack_a, t_stack **stack_b);
void				algo_medium(t_stack **stack_a, t_stack **stack_b);
void				algo_flag(t_stack **a, t_stack **b, char *flag);
int					is_sorted(t_stack *stack);
void				ft_swap_hide(t_stack **stack);
void				ft_push_hide(t_stack **src, t_stack **dest);
void				ft_rotate_hide(t_stack **stack);
void				ft_rrotate_hide(t_stack **stack);
int					read_and_apply(t_stack **a, t_stack **b);
void				no_duplicates(t_stack **stack);
long				ft_atoi_long(const char *str);
void				print_error(void);

#endif
