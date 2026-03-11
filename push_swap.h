/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miavrako <miavrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 08:11:14 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/10 22:17:14 by miavrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}					t_stack;

typedef struct s_bench
{
	int activated;
	int total_operation;
	int sa, sb, ss;
	int pa, pb;
	int ra, rb, rr;
	int rra, rrb, rrr;
	char *strategy;
	char *complexity;
}				t_bench;

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
double				disorder_metric(t_stack *stack, int size);
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
void				no_duplicate(t_stack **stack);
long				no_long_num(const char *str);
void				print_error(void);
void				*ft_memset(void *s, int v, size_t n);

#endif
