#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_push
{
	t_struct	*prev;
	int			num;
	t_struct	*next;
}	t_push;

#endif
