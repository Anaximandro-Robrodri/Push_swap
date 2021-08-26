# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: robrodri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/26 13:28:37 by robrodri          #+#    #+#              #
#    Updated: 2021/08/26 15:08:34 by robrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

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
LIBFT_DIR = ./libft/
LIBFT = libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: make-lift $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT_DIR)$(LIBFT) -o $(NAME)

make-lift:
	$(MAKE) -C $(LIBFT_DIR)

$(OBJS): $(SRC)
	$(CC) $(FLAGS) -c $(SRC)
clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -rf $(NAME)

re: fclean all

.PHONY: all re m clean fclean bonus
