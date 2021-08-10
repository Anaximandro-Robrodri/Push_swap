#include "push_swap.h"

void	ft_three_num (t_push **a)
{
	if ((*(*a)->num > *(*a)->next->num)
			&& (*(*a)->num > *(*a)->next->next->num))
		rotate(a, 1);
	if ((*(*a)->num > *(*a)->next->num)
			&& (*(*a)->num < *(*a)->next->next->num))
		swap(a, 1);
	if ((*(*a)->num < *(*a)->next->num)
			&& (*(*a)->next->num > *(*a)->next->next->num))
		reverse_rotate(a, 1);
	{
		if ((*(*a)->num > *(*a)->next->num)
			&& (*(*a)->num < *(*a)->next->next->num))
		swap(a, 1);
	}
}

void	ft_long_num(t_push **a, t_push **b)
{
	while (ft_len_lst(*a) > 3)
	{
		while (*(*a)->num != find_low(*a))
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
		if (*(*b)->num < *(*b)->next->num)
				swap(b, 0);
	}
	while (*b)
		push_a(a, b);
}

// INSERTION MODE -> FCKG SHIIIIIT
/*void	ft_serious_sorting_b(t_push **a, t_push **b)
{
	if ((*b) == NULL)
		return ;
	while (*(*b)->num != find_high(*b))
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
}*/

/*void	ft_serious_sorting(t_push **a, t_push **b)
{
	int		pivot;

	if ((*a) == NULL)
		return ;
	if (check_success (*a) == 1)
		return ;
	pivot = ft_pivot(*a, (ft_len_lst(*a) / 2) + 1);
	while (*(*a)->num != pivot)
	{
		if (*(*a)->num < pivot)
			push_b(a, b);
		else if (*(*a)->num > pivot)
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
}*/

/*void	ft_serious_sorting_b(t_push **a, t_push **b)
{
	int	high;

	high = find_high(*b);
	while (*(*b)->num != high)
	{
		if (find_half(*b, high) == 1)
			rotate(b, 0);
		else
			reverse_rotate(b, 0);
	}
}

void	ft_serious_sorting(t_push **a, t_push **b, int chunk)
{
	int	i;
	int	low;
	int	second;

	i = 0;
	while (i < chunk)
	{
		low = find_low(*a);
		second = find_second_low(*a, low);
		if (find_low(*a) < chunk)
		{
			if (ft_who_is_closer(*a, low, second) == 1)
			{
				if (find_half(*a, low) == 1)
				{
					while (*(*a)->num != low)
						rotate(a, 1);
				}
				else
				{
					while (*(*a)->num != low)
						reverse_rotate(a, 1);
				}
			}
			else
			{
				if (find_half(*a, second) == 1)
				{
					while (*(*a)->num != second)
						rotate(a, 1);
				}
				else
				{
					while (*(*a)->num != second)
						reverse_rotate(a, 1);
				}
			}
		}
		else
		{
			if (find_half(*a, low) == 1)
				{
					while (*(*a)->num != low)
						rotate(a, 1);
				}
			else
				{
					while (*(*a)->num != low)
						reverse_rotate(a, 1);
				}
		}
		push_b(a, b);
//		ft_serious_sorting_b(a, b);
		i++;
	}
}*/

void	ft_order(t_push	**stack_a, t_push **stack_b)
{
	int	len;
	int	*array;
	int **chunk;

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
	{
		array = bubble(*stack_a);
		chunk = get_chunky(array, len);
		int i = 0;
		while (i < 10)
			printf("%d\n", chunk[9][i++]);
	//	ft_serious_sorting(stack_a, stack_b);
		free(array);
		free(chunk);
	}
}
