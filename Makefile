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

ifeq ($(shell uname), Linux)
	CHECKER = ./checkers/checker_linux
else
	CHECKER = ./checkers/checker_Mac
endif
ARGS = "4 67 3 87 23"

test: all
	@./push_swap $(ARGS)

test_with_checker: all
	@./push_swap $(ARGS) | $(CHECKER) $(ARGS)

.PHONY: all clean fclean re test test_with_checker