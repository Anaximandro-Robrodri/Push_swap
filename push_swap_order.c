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

void	ft_long_num(t_push **a, t_push **b)
{
	while (ft_len_lst(*a) > 3)
	{
		while ((*a)->num != find_low(*a))
		{
			if (find_half(*a, find_low(*a)) == 1) 	
				rotate(a, 1);
			else
				reverse_rotate(a, 1);
		}
		push_b(a, b);
	}
	ft_three_num(a);
	if (ft_len_lst(*b) > 1)
	{
		if ((*b)->num < (*b)->next->num)
				swap(b, 0);
	}
	while (*b)
		push_a(a, b);
}

void	ft_serious_sorting_b(t_push **a, t_push **b)
{
	if ((*b) == NULL)
		return ;
	while ((*b)->num != find_high(*b))
	{
		if (find_half(*b, find_high(*b)) == 1)
			rotate(b, 0);
		else
			reverse_rotate(b, 0);
	}
	if (check_success(*a) == 0)
		ft_serious_sorting(a, b);
	push_a(a, b);
	while (ft_len_lst(*b))
		ft_serious_sorting_b(a, b);
}

void	ft_serious_sorting(t_push **a, t_push **b)
{
	int		pivot;

	if ((*a) == NULL)
		return ;
	pivot = ft_pivot(*a, ft_len_lst(*a));
	while ((*a)->num != pivot)
	{
		if ((*a)->num < pivot)
			push_b(a, b);
		else if ((*a)->num > pivot)
		{
			if (find_half(*a, find_low(*a)) == 1)
			{
				if (find_half(*b, find_high(*b)) == 1)
					rr(a, b);
				else
					rotate(a, 1);
			}
			else
			{
				if (find_half(*b, find_high(*b)) == 0)
					rrr(a, b);
				else
					reverse_rotate(a, 1);
			}
		}
	}
	if (check_success(*a) == 0)
		ft_serious_sorting(a, b);
	ft_serious_sorting_b(a, b);
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
	else if (len <= 5)
		ft_long_num(stack_a, stack_b);
	else
		ft_serious_sorting(stack_a, stack_b);
}
