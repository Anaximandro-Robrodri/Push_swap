#include "push_swap.h"

void	swap_a(t_push **stack_a)
{
	t_push	*tmp;

	if (ft_len_lst(*stack_a) < 2)
		return ;
	tmp = (*stack_a)->next->next;
	(*stack_a)->next->next = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_a)->next->next = tmp;
}

void	swap_b(t_push **stack_b)
{
	t_push	*tmp;

	if (ft_len_lst(*stack_b) < 2)
		return ;
	tmp = (*stack_b)->next->next;
	(*stack_b)->next->next = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_b)->next->next = tmp;
}

void	ss(t_push **stack_a, t_push **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}

void	rotate_a(t_push **stack_a)
{
	t_push	*tmp;
	t_push	*dsp;

	if (ft_len_lst(*stack_a) < 2)
		return ;
	tmp = *stack_a;
	dsp = tmp;
	*stack_a = (*stack_a)->next;
	while (dsp->next)
		dsp = dsp->next;
	dsp->next = tmp;
	tmp->next = NULL;
}

void	rotate_b(t_push **stack_b)
{
	t_push	*tmp;
	t_push	*dsp;

	if (ft_len_lst(*stack_b) < 2)
		return ;
	tmp = *stack_b;
	dsp = tmp;
	*stack_b = (*stack_b)->next;
	while (dsp->next)
		dsp = dsp->next;
	dsp->next = tmp;
	tmp->next = NULL;

}
