#include "push_swap.h"

void	ft_push_lst_new (int num, t_push *lst)
{
	lst = malloc(sizeof(t_push));
	if (lst == 0)
		return ;
	lst->top = NULL;
	lst->num = num;
	lst->bot = NULL;
}
