/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_five_hundred.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 13:28:58 by robrodri          #+#    #+#             */
/*   Updated: 2021/08/26 13:28:59 by robrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pivot(int *array, int i, int len)
{
	if (i == 1)
		return (array[((len / 4) / 2) - 1]);
	else if (i == 2)
		return (array[((len / 2) - ((len / 4) / 2)) - 1]);
	else if (i == 3)
		return (array[(((len / 2) + (len / 4)) - ((len / 4) / 2)) - 1]);
	else
		return (array[(len - ((len / 4) / 2)) - 1]);
}

int	get_quarter(int *array, int i, int len)
{
	if (i == 1)
		return (array[0]);
	else if (i == 2)
		return (array[(len / 4) - 1]);
	else if (i == 3)
		return (array[(len / 2) - 1]);
	else if (i == 4)
		return (array[((len / 2) + (len / 4) - 1)]);
	else
		return (array[len - 1]);
}

int	is_left(t_push *stack, int pivot, int quarter)
{
	t_push	*aux;

	aux = stack;
	while (aux)
	{
		if (*aux->num < pivot && *aux->num >= quarter)
			return (1);
		aux = aux->next;
	}
	return (0);
}

int	is_left_high(t_push *stack, int pivot, int quarter)
{
	t_push	*aux;

	aux = stack;
	while (aux)
	{
		if (*aux->num > pivot && *aux->num < quarter)
			return (1);
		aux = aux->next;
	}
	return (0);
}

void	init_pivot_points(t_pivot *p, int *array, int i, t_push *a)
{
	p->pivot = get_pivot(array, i, ft_len_lst(a));
	p->quarter = get_quarter(array, i, ft_len_lst(a));
	p->next_q = get_quarter(array, i + 1, ft_len_lst(a));
}
