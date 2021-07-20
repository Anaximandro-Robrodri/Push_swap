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
void	free_list(t_push **head);
void	print_list(t_push	*stack_a);

#endif
