# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smadie <smadie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/03 19:05:34 by smadie            #+#    #+#              #
#    Updated: 2022/03/11 07:14:25 by smadie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= push_swap

SRCS	= 	src/ft_atoi.c\
			src/ft_split.c\
			includes/ft_array.c\
			includes/ft_stacks.c\
			includes/ft_operations_1.c\
			includes/ft_operations_2.c\
			includes/ft_quik_sort.c\
			includes/ft_duplicate.c\
			includes/ft_5_or_3_sort.c\
			includes/ft_find_place.c\
			includes/ft_max_sort.c\
			includes/ft_validation.c\
			src/ft_error.c\
			includes/ft_operations_3.c\
			includes/push_swap.c\

HEADER	= push_swap.h
CFLAGS	= -Wall -Wextra -Werror
OBJS		= $(SRCS:%.c=%.o)
CC		= gcc

all:	$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(SRCS) $(CFLAGS) -o $(NAME)

%.o:	%.c $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:	clean
			$(RM) $(NAME)
			$(RM) *.out

re:		fclean all

.PHONY: all clean fclean re
