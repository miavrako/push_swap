NAME = push_swap
CHECKER = checker
CC = cc
FLAGS = -Wall -Wextra -Werror

SRC =	push_swap.c \
		algo_adaptive.c \
		algo_complex.c \
		algo_medium.c \
		algo_simple.c \
		disorder_metric.c \
		ft_push.c \
		ft_rotate.c \
		ft_rrotate.c \
		ft_swap.c \
		ft_utils.c \
		stack_utils.c \
		tiny_sort.c \
		push_swap_utils.c\
		ft_error.c

CHECKER_SRC =	checker.c \
				hide_ops.c \
				checker_apply.c \
				stack_utils.c \
				ft_utils.c

OBJ = $(SRC:.c=.o)
CHECKER_OBJ = $(CHECKER_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) ft_printf/libftprintf.a
	$(CC) $(FLAGS) $(OBJ) ./ft_printf/libftprintf.a -o $(NAME)
ft_printf/libftprintf.a :
	make -C ft_printf

bonus: $(CHECKER_OBJ)
	$(CC) $(FLAGS) $(CHECKER_OBJ) -o $(CHECKER)

%.o: %.c push_swap.h
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ) $(CHECKER_OBJ)
	make -C ft_printf clean
fclean: clean
	rm -f $(NAME) $(CHECKER)
	make -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re bonus
