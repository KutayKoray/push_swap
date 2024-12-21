NAME	= push_swap

CFLAGS	= -Wall -Wextra -Werror

SRCS	= check_arg.c free.c ft_atoi.c ft_split.c helper.c \
		push_swap.c radix.c sort_three.c utils.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re