/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miavrako <miavrako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 08:11:14 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/12 23:55:12 by miavrako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int					content;
	int					index;
	struct s_stack		*next;
}						t_stack;

typedef struct s_bench
{
	t_stack				*a;
	t_stack				*b;
	char		*strategy;
	double		disorder_metric;
	char		*complexity;
	int			total_op;
	char		*operation;
}						t_bench;

typedef struct s_operation
{
	t_stack				*a;
	t_stack				*b;
	int					op_count;
	char				*operation;
	struct s_operation	*next;
}						t_operation;

typedef struct s_opstats
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_opstats;

t_stack		*ft_lstlast(t_stack *lst);
int			stack_size(t_stack *stack);
int			find_min_index(t_stack *stack);
void		assign_indices(t_stack *stack);
void		pa(t_stack **stack_a, t_stack **stack_b, t_operation **op);
void		pb(t_stack **stack_a, t_stack **stack_b, t_operation **op);
void		ra(t_stack **stack_a, t_operation **op);
void		rra(t_stack **stack_a, t_operation **op);
void		sa(t_stack **stack_a, t_operation **op);
void		rb(t_stack **stack_b, t_operation **op);
void		rrb(t_stack **stack_b, t_operation **op);
void		rr(t_stack **stack_a, t_stack **stack_b, t_operation **op);
void		rrr(t_stack **stack_a, t_stack **stack_b, t_operation **op);
void		sb(t_stack **stack_b, t_operation **op);
void		ss(t_stack **stack_a, t_stack **stack_b, t_operation **op);
void		sort_two(t_stack **a, t_stack **b);
void		sort_three(t_stack **a, t_stack **b);
void		sort_five(t_stack **a, t_stack **b);
void		algo_complex(t_stack **a, t_stack **b);
void		ft_putstr_fd(char *s, int fd);
double		disorder_metric(t_stack *stack, int size);
void		algo_adaptive(t_stack **a, t_stack **b);
void		algo_simple(t_stack **stack_a, t_stack **stack_b);
void		algo_medium(t_stack **stack_a, t_stack **stack_b);
void		algo_flag(t_stack **a, t_stack **b, char *flag);
int			is_sorted(t_stack *stack);
int			num_duplicate(t_stack **stack, int value);
void		print_error(void);
char		**ft_split(char const *s, char c);
int			ft_strcmp(const char *s1, const char *s2);
void		add_operation(t_operation **lst, char *operation);
void		print_operation(t_operation *op);
void	init_bench(t_bench *bench);
void	set_strategy(t_bench *bench);
void	set_complexity(t_bench *bench);
void	set_total_op(t_bench *bench, t_operation *op);
void	count_operation(t_operation *ops, t_opstats *s);
void	print_operation_stats(t_opstats *s);
void	print_bench(t_bench *bench);
int	bench_activated(int argc, char **argv);
void	stack_a_valid(t_stack **stack_a, char **argv);
void	free_split(char **split);
t_stack	*stack_copy(t_stack *stack);

#endif
