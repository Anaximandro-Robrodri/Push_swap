#include "push_swap.h"

void	ft_three_num (t_push **a)
{
	if (((*a)->num > (*a)->next->num)
			&& ((*a)->num > (*a)->next->next->num))
		rotate_a(a);
	if (((*a)->num > (*a)->next->num)
			&& ((*a)->num < (*a)->next->next->num))
		swap_a(a);
	if (((*a)->num < (*a)->next->num)
			&& ((*a)->next->num > (*a)->next->next->num))
		reverse_rotate_a(a);
	{
		if (((*a)->num > (*a)->next->num)
			&& ((*a)->num < (*a)->next->next->num))
		swap_a(a);
	}
}

void	ft_order(t_push	**stack_a, t_push **stack_b)
{
	int	len;

	check_success(*stack_a);
	len = ft_len_lst(*stack_a);
	stack_b = NULL;
	if (len == 3)
		ft_three_num(stack_a);
/*	else if (len < 6)
		ft_five_num(stack_a, stack_b);*/
}
