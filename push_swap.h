/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirarand <mirarand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 08:11:14 by mirarand          #+#    #+#             */
/*   Updated: 2026/03/19 07:55:13 by mirarand         ###   ########.fr       */
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

typedef struct s_operation
{
	char				*operation;
	struct s_operation	*next;
}						t_operation;

typedef struct s_bench
{
	t_stack				*a;
	t_stack				*b;
	char				*strategy;
	char				*forced_flag;
	double				disorder_metric;
	char				*complexity;
	int					total_op;
	t_operation			*operation;
}						t_bench;

typedef struct s_program
{
	t_operation			*op;
	int					sa;
	int					sb;
	int					ss;
	int					pa;
	int					pb;
	int					ra;
	int					rb;
	int					rr;
	int					rra;
	int					rrb;
	int					rrr;
}						t_program;

typedef struct s_run
{
	char	*flag;
	int		bench;
	int		from_split;
}			t_run;

t_stack	*ft_lstlast(t_stack *lst);
int		stack_size(t_stack *stack);
int		find_min_index(t_stack *stack);
void	assign_indices(t_stack *stack);
void	pa(t_stack **stack_a, t_stack **stack_b, t_operation **ops);
void	pb(t_stack **stack_a, t_stack **stack_b, t_operation **ops);
void	ra(t_stack **stack_a, t_operation **ops);
void	rra(t_stack **stack_a, t_operation **ops);
void	sa(t_stack **stack_a, t_operation **ops);
void	rb(t_stack **stack_b, t_operation **ops);
void	rrb(t_stack **stack_b, t_operation **ops);
void	rr(t_stack **stack_a, t_stack **stack_b, t_operation **ops);
void	rrr(t_stack **stack_a, t_stack **stack_b, t_operation **ops);
void	sb(t_stack **stack_b, t_operation **ops);
void	ss(t_stack **stack_a, t_stack **stack_b, t_operation **ops);
void	sort_two(t_stack **a, t_stack **b, t_operation **op);
void	sort_three(t_stack **a, t_stack **b, t_operation **op);
void	sort_five(t_stack **a, t_stack **b, t_operation **op);
void	algo_complex(t_stack **a, t_stack **b, t_operation **op);
void	ft_putstr_fd(char *s, int fd);
float	disorder_metric(t_stack *stack, int size);
void	algo_adaptive(t_stack **a, t_stack **b, t_operation **op);
void	algo_simple(t_stack **stack_a, t_stack **stack_b, t_operation **op);
void	algo_medium(t_stack **stack_a, t_stack **stack_b, t_operation **op);
void	algo_flag(t_stack **a, t_stack **b, char *flag, t_operation **op);
int		is_sorted(t_stack *stack);
int		num_duplicate(t_stack *stack, int value);
void	print_error(void);
char	**ft_split(char const *s, char c);
int		ft_strcmp(const char *s1, const char *s2);
void	add_operation(t_operation **lst, char *value);
void	print_operation(t_operation *op);
void	init_bench(t_bench *bench);
void	set_strategy(t_bench *bench);
void	set_complexity(t_bench *bench);
void	count_operations(t_operation *ops, t_program *s);
void	count_operations2(t_operation *ops, t_program *s);
void	print_bench(t_bench *bench);
int		bench_activated(int argc, char **argv);
void	stack_a_valid(t_stack **stack_a, char **argv);
void	free_split(char **split);
void	*ft_memset(void *s, int v, size_t n);
void	ft_lstclear(t_operation **lst, void (*del)(void *));
void	push_back(t_stack **stack, int value);
void	run_bench(int active, t_stack *a, t_operation *op, char *flag);
char	*get_algo_flag(int argc, char **argv);
void	free_stack(t_stack *stack);
t_stack	*stack_copy(t_stack *src);
void	resolve_strategy(t_bench *bench);
#endif
