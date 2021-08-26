# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: robrodri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/26 13:28:37 by robrodri          #+#    #+#              #
#    Updated: 2021/08/26 13:28:39 by robrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./libft/libft.a

NAME = push_swap.a

SRC =	push_swap.c \
		push_swap_utils.c \
		push_swap_utils_2.c \
		push_swap_lst_utils.c \
		push_swap_moves.c \
		push_swap_moves_2.c \
		push_swap_order.c \
		push_swap_order_2.c \
		push_swap_five_hundred.c \
		push_swap_five_hundred_2.c

OBJS = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJS)
	CC $(NAME) -o push_swap

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all re m clean fclean bonus
