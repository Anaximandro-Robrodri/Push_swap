#include "push_swap.h"

void	swap(t_push **stack)
{
	t_push	*tmp;

	if (ft_len_lst(*stack) < 2)
		return ;
	tmp = (*stack)->next->next;
	(*stack)->next->next = *stack;
	*stack = (*stack)->next;
	(*stack)->next->next = tmp;
}

void	ss(t_push **stack_a, t_push **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

void	rotate(t_push **stack)
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
}
