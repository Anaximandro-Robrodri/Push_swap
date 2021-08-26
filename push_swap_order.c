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

void	ft_sort_hundred(t_push **a, t_push **b, int pivot)
{
	while (1)
	{
		if (*(*a)->num < pivot)
		{
			push_b(a, b);
			if (!check_left((*a), pivot))
				break ;
		}
		else
			rotate(a, 1);
	}
	sort_b(a, b);
	while (*(*a)->num < pivot)
		rotate(a, 1);
	while (*(*a)->num != find_low(*a))
	{
		if (*(*a)->num > pivot)
			push_b(a, b);
		else if (*(*a)->num == pivot)
			rotate(a, 1);
	}
	sort_b(a, b);
	while (*(*a)->num != find_low(*a))
		rotate(a, 1);
}

static int get_pivot(int *array, int i, int len)
{
	if (i == 1)
		return(array[((len / 4) / 2) - 1]);
	else if (i == 2)
		return(array[((len / 2) - ((len / 4) / 2)) - 1]);
	else if (i == 3)
		return(array[(((len / 2) + (len / 4)) - ((len / 4) / 2)) - 1]);
	else
		return(array[(len - ((len / 4) / 2)) - 1]);
}

static int get_quarter(int *array, int i, int len)
{
	if (i == 1)
		return(array[0]);
	else if (i == 2)
		return(array[(len / 4) - 1]);
	else if (i == 3)
		return(array[(len / 2) - 1]);
	else if (i == 4)
		return(array[((len / 2) + (len / 4) - 1)]);
	else
		return(array[len - 1]);
}

static int is_left(t_push *stack, int pivot, int quarter)
{
	t_push	*aux;

	aux = stack;
	while (aux)
	{
		if (*aux->num < pivot && *aux->num >= quarter)
			return (1);
		aux = aux->next;
	}
	return(0);
}

static int is_left_high(t_push *stack, int pivot, int quarter)
{
	t_push *aux;

	aux = stack;
	while(aux)
	{
		if(*aux->num > pivot && *aux->num < quarter)
			return(1);
		aux = aux->next;
	}
	return(0);
}

void	ft_quarter(t_push **a, t_push **b, int i, int *array)
{
	int	pivot;
	int	quarter;
	int	next_q;

	pivot = get_pivot(array, i, ft_len_lst(*a));
	quarter = get_quarter(array, i, ft_len_lst(*a));
	next_q = get_quarter(array, i + 1, ft_len_lst(*a));
	while(1)
	{
		if(*(*a)->num <= pivot && *(*a)->num >= quarter)
		{
			push_b(a, b);
			if (!is_left(*a, pivot, quarter))
				break ;
		}
		else
			rotate(a, 1);
	}
	sort_b(a, b);
	while(*(*a)->num <= pivot && *(*a)->num < next_q)
		rotate(a, 1);
	while(1)
	{
		if(*(*a)->num > pivot && *(*a)->num <= next_q)
		{
			push_b(a,b);
			if (!is_left_high(*a, pivot, next_q))
				break ;
		}
		else
			rotate(a, 1);
	}
	while(*(*a)->num != pivot)
		reverse_rotate(a, 1);
	rotate(a, 1);
//	print_list(*a, *b);
//	printf("pivot   %d\n", pivot);
//	printf("quarter %d\n", quarter);
//	printf("next_q  %d\n", next_q);
	sort_b(a, b);
	while (*(*a)->num != next_q)
		rotate(a, 1);
	rotate(a, 1);
//	print_list(*a, *b);
}

void	ft_order(t_push	**stack_a, t_push **stack_b)
{
	int	len;
	int	*array;

	if (check_success(*stack_a) == 1)
		return ;
	len = ft_len_lst(*stack_a);
	if (len == 2)
		swap(stack_a, 1);
	else if (len == 3)
		ft_three_num(stack_a);
	else if (len <= 9)
		ft_long_num(stack_a, stack_b);
	array = bubble(*stack_a);
	if (len <= 100)
	{
		ft_sort_hundred(stack_a, stack_b, array[(len / 2) - 1]);
		free(array);
	}
	else
	{
		ft_quarter(stack_a, stack_b, 1, array);
		ft_quarter(stack_a, stack_b, 2, array);
		ft_quarter(stack_a, stack_b, 3, array);
		ft_quarter(stack_a, stack_b, 4, array);
		free(array);
	}
}
