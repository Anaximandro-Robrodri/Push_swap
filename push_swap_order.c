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

void	ft_serious_sorting_b(t_push **a, t_push **b,  int *array, int len)
{
	int	i;

	i = 0;
	while ((*b) && len)
	{
		while (array[len] != *(*b)->num)
		{
			if ((*b)->next && array[len] == *(*b)->num)
				swap(b, 0);
			else
			{
				rotate(b, 0);
				i++;
			}
		}
		while (*b && array[len] == *(*b)->num)
		{
			push_a(a, b);
			len--;
		}
		while (*b && i > 0)
		{
			reverse_rotate(b, 0);
			i--;
			if (array[len] == *(*b)->num)
				break ;
		}
	}
}

void	sort_b(t_push **a, t_push **b, long *chunk_1, long *chunk_2)
{
	if ((*a) && !check_chunky(chunk_2, *(*a)->num)
		&& !check_chunky(chunk_1, *(*a)->num) && check_chunky(chunk_1, *(*b)->num))
			rr(a, b);
	else
		rotate(b, 0);
}

void	ft_serious_sorting(t_push **a, t_push **b, long **chunk, int chunk_l)
{
	int	i;
	int	j;

	// i es el de la mitad, a el siguiente
	i = (chunk_l / 2) - 1;
	j = i + 1;
	while ((*a) && j < chunk_l)
	{
		while ((*a) && (!check_chunky(chunk[i], *(*a)->num)
				&& !check_chunky(chunk[j], *(*a)->num)))
		{
			if (check_chunky(chunk[i], last_val(*a))
				|| check_chunky(chunk[j], last_val(*a)))
				reverse_rotate(a, 1);
			else
				rotate(a, 1);
		}
		while ((*a) && (check_chunky(chunk[i], *(*a)->num)
				|| check_chunky(chunk[j], *(*a)->num)))
		{
			push_b(a, b);
//			if (ft_len_lst(*b) > 1)
//				sort_b(a, b, chunk[i], chunk[j]);
		}
		if ((*a) && !not_in_stack(*a, chunk[i]) && i > 0)
			i--;
		if ((*a) && !not_in_stack(*a, chunk[j]) && j < chunk_l - 1)
			j++;
	}
}

void	ft_order(t_push	**stack_a, t_push **stack_b)
{
	int	len;
	int	*array;
	long **chunk;

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
		chunk = get_chunky(array, len, (len / 11));
		ft_serious_sorting(stack_a, stack_b, chunk, 11);
		ft_serious_sorting_b(stack_a, stack_b, array, len - 1);
		free(array);
		free(chunk);
	}
}
