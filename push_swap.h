#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_push
{
	struct	s_push	*top;
	int				num;
	struct	s_push	*bot;
}	t_push;

int		main (int argc, char **argv);
int 	ft_is_space (char a);
int 	ft_is_sign (char a);
int		ft_split_len(char **str);
long	ft_atoi_plus(char *str);
//char	*ft_move_atoi(char *str);
void	ft_error(int i);

//////////////////////////////////////////////////////////////
// LST FUNCTIONS

 void  ft_push_lst_new (int num, t_push *lst);

#endif
