#include "push_swap.h"

void	ft_sort_b(t_push **a, t_push **b, int pivot)
{
	t_push	*tmp;

	tmp = *b;
	while (tmp)
	{
		if (tmp->num == pivot)
		{
			rotate(b, 0);
			break ;
		}
		else
			reverse_rotate(b, 0);
		tmp = tmp->next;
	}
	while (ft_len_lst(*b))
		push_a(a, b);
	return ;
}

void	ft_sort_a(t_push **a, t_push **b, int pivot)
{
	t_push	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->num < pivot)
			push_b(a, b);
		else if (tmp->num == pivot)
		{
			reverse_rotate(a, 1);
			break ;
		}
		else
			rotate(a, 1);
		tmp = tmp->next;
	}
	if (ft_len_lst(*a) == 3)
	{
		ft_three_num(a);
		push_a(a, b);
		return;
	}
	else
	{
		while (check_success(*a) == 0)
			ft_sort_a(a, b, ft_pivot(*a, (ft_len_lst(*a) / 2)));
		if (*b)
			ft_sort_b(a, b, ft_pivot(*b, (ft_len_lst(*b) / 2)));
	}
	return ;
}
