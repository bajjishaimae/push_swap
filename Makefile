# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/27 12:10:30 by cbajji            #+#    #+#              #
#    Updated: 2024/06/28 15:46:55 by cbajji           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
NAME		=	push_swap

SRC			=	instructions.c libft_functions1.c libft_functions2.c parsing.c push_swap.c sorting.c utiles1.c utiles2.c utiles3.c

OBJS        = $(SRC:.c=.o)

all         : $(NAME)

$(NAME)     : $(OBJS)
	            $(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o			:	%.c push_swap.h
			$(CC) $(CFLAGS) -c $< -o $@

clean       :
	            @rm -f $(OBJS)

fclean      : clean
	            @rm -f $(NAME)

re          : fclean all

.PHONY      : clean