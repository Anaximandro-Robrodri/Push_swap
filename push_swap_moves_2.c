/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 13:29:19 by robrodri          #+#    #+#             */
/*   Updated: 2021/08/26 13:29:20 by robrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_push **stack_a, t_push **stack_b)
{
	rotate(stack_a, 2);
	rotate(stack_b, 2);
	ft_putstr("rr\n");
}

void	reverse_rotate(t_push **stack, int i)
{
	t_push	*tmp;
	t_push	*dsp;
	int		len;

	len = ft_len_lst(*stack);
	if (len < 2)
		return ;
	dsp = *stack;
	while (dsp->next)
	{
		tmp = dsp;
		dsp = dsp->next;
	}
	dsp->next = (*stack);
	*stack = dsp;
	tmp->next = NULL;
	if (i == 1)
		ft_putstr("rra\n");
	else if (i == 0)
		ft_putstr("rrb\n");
}

void	rrr(t_push **stack_a, t_push **stack_b)
{
	reverse_rotate(stack_a, 2);
	reverse_rotate(stack_b, 2);
	ft_putstr("rrr\n");
}
