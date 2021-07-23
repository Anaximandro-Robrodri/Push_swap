#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_push
{
	int				num;
	struct	s_push	*next;
}	t_push;

int		main (int argc, char **argv);
int 	ft_is_space (char a);
int 	ft_is_sign (char a);
int		ft_split_len(char **str);
long	ft_atoi_plus(char *str);
void	ft_error(int i);
void	ft_print_success(int i, t_push *stack_a);

//////////////////////////////////////////////////////////////
// LST FUNCTIONS

t_push	*create_new_node(int num);
void	print_list(t_push	*stack_a);
int		ft_len_lst(t_push *stack_a);
void	ft_check_equals(t_push *stack_a);
void	ft_store_args(t_push **stack, int num);
int		check_success(t_push *stack_a);

/////////////////////////////////////////////////////////////
//MOVEMENTS

void	swap(t_push **stack, int i);
void	ss(t_push **stack_a, t_push **stack_b);
void	rotate(t_push **stack, int i);
void	rr(t_push **stack_a, t_push **stack_b);
void	reverse_rotate(t_push **stack, int i);
void	rrr(t_push **stack_a, t_push **stack_b);
void	push_b(t_push **stack_a, t_push **stack_b);
void	push_a(t_push **stack_a, t_push **stack_b);

//////////////////////////////////////////////////////////////
//OPERATIONS ORDER
void	ft_order(t_push **stack_a, t_push **stack_b);
void	ft_three_num(t_push **a);
void	ft_five_num(t_push **a, t_push **b, int len);

#endif
