#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "./libft/libft.h"

/*typedef struct s_push
{
	t_struct	*prev;
	int			num;
	t_struct	*next;
}	t_push;
*/
int		main (int argc, char **argv);
int 	ft_is_space (char a);
int 	ft_is_sign (char a);
long	ft_atoi_plus(char *str);
void	ft_error(int i);

#endif
