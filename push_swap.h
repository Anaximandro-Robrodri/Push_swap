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
	struct	s_push	*prev;
}	t_push;

int		main (int argc, char **argv);
int 	ft_is_space (char a);
int 	ft_is_sign (char a);
int		ft_split_len(char **str);
long	ft_atoi_plus(char *str);
void	ft_error(int i);

//////////////////////////////////////////////////////////////
// LST FUNCTIONS

t_push	*create_new_node(int num);
void	print_list(t_push	*stack_a);
int		ft_len_lst(t_push *stack_a);
void	ft_check_equals(t_push *stack_a);

/////////////////////////////////////////////////////////////
//MOVEMENTS

void	swap_a(t_push **stack_a);
void	swap_b(t_push **stack_b);
void	ss(t_push **stack_a, t_push **stack_b);
void	rotate_a(t_push **stack_a);
void	rotate_b(t_push **stack_b);
void	rr(t_push **stack_a, t_push **stack_b);
void	reverse_rotate_a(t_push **stack_a);
void	reverse_rotate_b(t_push **stack_b);
void	rrr(t_push **stack_a, t_push **stack_b);

#endif
