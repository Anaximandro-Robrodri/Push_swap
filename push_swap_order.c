/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_order.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 13:29:26 by robrodri          #+#    #+#             */
/*   Updated: 2021/08/26 13:29:27 by robrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_three_num(t_push **a)
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

void	ft_quarter(t_push **a, t_push **b, int i, int *array)
{
	t_pivot	p;

	init_pivot_points(&p, array, i, *a);
	first_cycle(p, a, b);
	sort_b(a, b);
	second_cycle(p, a, b);
	while (*(*a)->num != p.pivot)
		reverse_rotate(a, 1);
	rotate(a, 1);
	sort_b(a, b);
	while (*(*a)->num != p.next_q)
		rotate(a, 1);
	rotate(a, 1);
}

void	ft_order(t_push	**stack_a, t_push **stack_b)
{
	int	len;
	int	*array;

	if (check_success(*stack_a) == 1)
		return ;
	array = bubble(*stack_a);
	len = ft_len_lst(*stack_a);
	if (len == 2)
		swap(stack_a, 1);
	else if (len == 3)
		ft_three_num(stack_a);
	else if (len <= 9)
		ft_long_num(stack_a, stack_b);
	else if (len <= 100)
		ft_sort_hundred(stack_a, stack_b, array[(len / 2) - 1]);
	else
	{
		ft_quarter(stack_a, stack_b, 1, array);
		ft_quarter(stack_a, stack_b, 2, array);
		ft_quarter(stack_a, stack_b, 3, array);
		ft_quarter(stack_a, stack_b, 4, array);
	}
	free(array);
}
