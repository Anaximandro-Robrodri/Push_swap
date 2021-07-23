#include "push_swap.h"

void	push_b(t_push **stack_a, t_push **stack_b) // DE A PASA AL STACK B
{
	t_push	*tmp;

	if (ft_len_lst(*stack_a) < 1)
		return ;
	ft_store_args(stack_b, (*stack_a)->num);
	tmp = (*stack_a)->next;
	free(*stack_a);
	*stack_a = tmp;
}

void	push_a(t_push **stack_a, t_push **stack_b) // DE B PASA AL STACK A
{
	t_push	*tmp;

	if (ft_len_lst(*stack_b) < 1)
		return ;
	ft_store_args(stack_a, (*stack_b)->num);
	tmp = (*stack_b)->next;
	free(*stack_b);
	*stack_b = tmp;
}
