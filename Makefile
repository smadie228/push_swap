# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smadie <smadie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/03 19:05:34 by smadie            #+#    #+#              #
#    Updated: 2022/03/10 22:28:36 by smadie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= push_swap
CC		= gcc
SRCS	= 	includes/ft_atoi.c\
			includes/ft_split.c\
			includes/ft_array.c\
			includes/ft_stacks.c\
			includes/ft_operations_1.c\
			includes/ft_operations_2.c\
			includes/ft_quik_sort.c\
			includes/ft_duplicate.c\
			includes/ft_5_or_3_sort.c\
			includes/ft_find_place.c\
			includes/ft_max_sort.c\
			push_swap.c\

OBJS 	= $(SRCS:%.c=%.o)

all:	$(NAME)

$(NAME):	$(OBJS)
				$(CC) $(SRCS)   -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean: clean
			$(RM) $(NAME)
			$(RM) *.out

re:		fclean all

.PHONY: all clean fclean re
