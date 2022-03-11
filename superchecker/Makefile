NAME	= checker

SRCS	= main.c ft_split.c ft_split_utils.c\
		check_argv.c list_utils.c utils.c\
		commands.c union_commands.c\
		get_next_line_utils.c\
		get_next_line.c\
		utils_two.c

OBJS	= $(SRCS:.c=.o)

HEADER	= checker.h

CFLAGS	= -Wall -Wextra -Werror -I $(HEADER)

CC		= gcc

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all
