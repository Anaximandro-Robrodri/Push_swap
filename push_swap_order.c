#include "push_swap.h"

void	ft_three_num (t_push **a)
{
	if (((*a)->num > (*a)->next->num)
			&& ((*a)->num > (*a)->next->next->num))
		rotate(a, 1);
	if (((*a)->num > (*a)->next->num)
			&& ((*a)->num < (*a)->next->next->num))
		swap(a, 1);
	if (((*a)->num < (*a)->next->num)
			&& ((*a)->next->num > (*a)->next->next->num))
		reverse_rotate(a, 1);
	{
		if (((*a)->num > (*a)->next->num)
			&& ((*a)->num < (*a)->next->next->num))
		swap(a, 1);
	}
}

void	ft_long_num(t_push **a, t_push **b, int len)
{
	int		pivot;
	t_push	*tmp;

	tmp = *a;
	pivot = ft_pivot(tmp, (len / 2));
	ft_sort_a(a, b, pivot);
}

void	ft_order(t_push	**stack_a, t_push **stack_b)
{
	int	len;

	if (check_success(*stack_a) == 1)
		return ;
	len = ft_len_lst(*stack_a);
	if (len == 2)
		swap(stack_a, 1);
	else if (len == 3)
		ft_three_num(stack_a);
	else if (len > 3)
		ft_long_num(stack_a, stack_b, len);
}
