#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}					t_stack;

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}					t_list;

void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);
t_list				*ft_lstlast(t_list *lst);
int					ft_lstsize(t_list *lst);

#endif
