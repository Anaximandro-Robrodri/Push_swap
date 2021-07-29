LIBFT = ./libft/libft.a

NAME = push_swap.a

SRC =	push_swap.c \
		push_swap_utils.c \
		push_swap_lst_utils.c \
		push_swap_moves.c \
		push_swap_moves_2.c \
		push_swap_order.c \
		push_swap_order_2.c

OBJS = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJS)
<<<<<<< HEAD
	CC $(NAME) -o push_swap 
	#-g3 -fsanitize=address
=======
	CC $(NAME) -o push_swap
>>>>>>> 374f78e

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all re m clean fclean bonus

