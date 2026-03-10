CC = cc

FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS = ft_putnbr.c ft_printf.c str_utils.c print_utils.c

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME):$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re clean

