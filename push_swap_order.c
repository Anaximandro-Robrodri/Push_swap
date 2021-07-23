#include "push_swap.h"

void	ft_three_num (t_push **a)
{
	if (((*a)->num > (*a)->next->num)
			&& ((*a)->num > (*a)->next->next->num))
		rotate(a);
	if (((*a)->num > (*a)->next->num)
			&& ((*a)->num < (*a)->next->next->num))
		swap(a);
	if (((*a)->num < (*a)->next->num)
			&& ((*a)->next->num > (*a)->next->next->num))
		reverse_rotate(a);
	{
		if (((*a)->num > (*a)->next->num)
			&& ((*a)->num < (*a)->next->next->num))
		swap(a);
	}
}

void	ft_five_num(t_push **a, t_push **b, int len)
{
	push_b(a, b);
	if (len == 5)
		push_b(a, b);
	ft_three_num(a);
	if (ft_len_lst(*b) > 1)
	{
		if ((*b)->num < (*b)->next->num)
			swap(b);
	}
	push_a(a, b);
}

void	ft_order(t_push	**stack_a, t_push **stack_b)
{
	int	len;

	if (check_success(*stack_a) == 1)
		return ;
	len = ft_len_lst(*stack_a);
	if (len == 2)
		swap(stack_a);
	else if (len == 3)
		ft_three_num(stack_a);
	else if (len <= 5)
		ft_five_num(stack_a, stack_b, len);
}
