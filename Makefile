NAME = push_swap
CC = cc

SRC=push_swap.c \
	algo_adaptive.c \
	algo_complex.c \
	algo_simple.c \
	disorder_metric.c \
	ft_push.c \
	ft_rotate.c \
	ft_rrotate.c \
	ft_swap.c \
	ft_utils.c \
	stack_utils.c \
	tiny_sort.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all:$(NAME)

$(NAME):$(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
