/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_five_hundred_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 13:29:04 by robrodri          #+#    #+#             */
/*   Updated: 2021/08/30 11:36:41 by robrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_cycle(t_pivot p, t_push **a, t_push **b)
{
	while (1)
	{
		if ((*a)->num <= p.pivot && (*a)->num >= p.quarter)
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
	while ((*a)->num <= p.pivot && (*a)->num < p.next_q)
		rotate(a, 1);
	while (1)
	{
		if ((*a)->num > p.pivot && (*a)->num <= p.next_q)
		{
			push_b(a, b);
			if (!is_left_high(*a, p.pivot, p.next_q))
				break ;
		}
		else
			rotate(a, 1);
	}
}

static int	int_max_check(char *ptr)
{
	char		**split;
	int			i;

	split = ft_split(ptr, ' ');
	i = 0;
	while (split[i])
	{
		if (ft_atoi_plus(split[i]) > INT_MAX
			|| ft_atoi_plus(split[i]) < INT_MIN)
		{
			while (split[i])
			{
				free(split[i]);
				i++;
			}
			free(split);
			return (0);
		}
		free(split[i]);
		i++;
	}
	free(split);
	return (1);
}

int	not_good_argv(int argc, char **argv)
{
	while (--argc)
	{
		if (!ft_error_control(argc, argv))
			return (0);
		if (!int_max_check(argv[argc]))
			return (0);
	}
	return (1);
}

void	free_list(t_push **stack)
{
	t_push	*aux;

	while (*stack)
	{
		aux = (*stack)->next;
		free(*stack);
		*stack = aux;
	}
}
