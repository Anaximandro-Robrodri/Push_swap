#include "push_swap.h"

void	rr(t_push **stack_a, t_push **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

void	reverse_rotate(t_push **stack)
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
}

void	rrr(t_push **stack_a, t_push **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
