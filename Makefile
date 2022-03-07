# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smadie <smadie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/03 19:05:34 by smadie            #+#    #+#              #
#    Updated: 2022/03/07 13:50:49 by smadie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= push_swap
CC		= gcc
SRCS	= 	includes/ft_atoi.c\
			includes/ft_split.c\
			includes/ft_array.c\
			main2.c\



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
