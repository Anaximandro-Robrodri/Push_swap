/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_five_hundred_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 13:29:04 by robrodri          #+#    #+#             */
/*   Updated: 2021/08/26 13:29:05 by robrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_cycle(t_pivot p, t_push **a, t_push **b)
{
	while (1)
	{
		if (*(*a)->num <= p.pivot && *(*a)->num >= p.quarter)
		{
			push_b(a, b);
			if (!is_left(*a, p.pivot, p.quarter))
				break ;
		}
		else
			rotate(a, 1);
	}
}

void	second_cycle(t_pivot p, t_push **a, t_push **b)
{
	while (*(*a)->num <= p.pivot && *(*a)->num < p.next_q)
		rotate(a, 1);
	while (1)
	{
		if (*(*a)->num > p.pivot && *(*a)->num <= p.next_q)
		{
			push_b(a, b);
			if (!is_left_high(*a, p.pivot, p.next_q))
				break ;
		}
		else
			rotate(a, 1);
	}
}
