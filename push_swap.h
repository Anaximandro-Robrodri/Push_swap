#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_push
{
	int		*num;
	struct	s_push	*next;
	struct	s_push	*prev;
}	t_push;

int 	ft_is_space (char a);
int 	ft_is_sign (char a);
int		ft_split_len(char **str);
long	ft_atoi_plus(char *str);
void	ft_error(int i);

//////////////////////////////////////////////////////////////
// LST FUNCTIONS

t_push	*create_new_node(int *num);
void	print_list(t_push *stack_a, t_push *stack_b);
int		ft_len_lst(t_push *stack_a);
void	ft_check_equals(t_push *stack_a);
void	ft_store_args(t_push **stack, int *num);
int		check_success(t_push *stack_a);
int	smart_rotate(int high, int low, t_push *stack);
int	check_left(t_push *a, int pivot);

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
void	ft_long_num(t_push **a, t_push **b);
int		find_high(t_push *stack);
int		find_low(t_push	*stack);
int		find_half(t_push *stack, int num);
int 	*ft_sort_int_tab(int *tab, int size);
int 	*bubble(t_push *s);
void	ft_sort_hundred(t_push **a, t_push **b, int pivot);
void	ft_quarter(t_push **a, t_push **b, int i, int *array);
void	sort_b(t_push **a, t_push **b);

#endif
