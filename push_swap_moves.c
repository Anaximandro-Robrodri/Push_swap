/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 13:29:13 by robrodri          #+#    #+#             */
/*   Updated: 2021/08/26 13:29:14 by robrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_push **stack, int i)
{
	t_push	*tmp;

	if (ft_len_lst(*stack) < 2)
		return ;
	tmp = (*stack)->next->next;
	(*stack)->next->next = *stack;
	*stack = (*stack)->next;
	(*stack)->next->next = tmp;
	if (i == 1)
		ft_putstr("sa\n");
	else if (i == 0)
		ft_putstr("sb\n");
}

void	ss(t_push **stack_a, t_push **stack_b)
{
	swap(stack_a, 2);
	swap(stack_b, 2);
	ft_putstr("ss\n");
}

void	rotate(t_push **stack, int i)
{
	t_push	*tmp;
	t_push	*dsp;

	if (ft_len_lst(*stack) < 2)
		return ;
	tmp = *stack;
	dsp = tmp;
	*stack = (*stack)->next;
	while (dsp->next)
		dsp = dsp->next;
	dsp->next = tmp;
	tmp->next = NULL;
	if (i == 1)
		ft_putstr("ra\n");
	else if (i == 0)
		ft_putstr("rb\n");
}

void	push_b(t_push **stack_a, t_push **stack_b)
{
	t_push	*tmp;

	if (ft_len_lst(*stack_a) < 1)
		return ;
	ft_store_args(stack_b, (*stack_a)->num);
	tmp = (*stack_a)->next;
	free(*stack_a);
	*stack_a = tmp;
	ft_putstr("pb\n");
}

void	push_a(t_push **stack_a, t_push **stack_b)
{
	t_push	*tmp;

	if (ft_len_lst(*stack_b) < 1)
		return ;
	ft_store_args(stack_a, (*stack_b)->num);
	tmp = (*stack_b)->next;
	free(*stack_b);
	*stack_b = tmp;
	ft_putstr("pa\n");
}
