#include "push_swap.h"

void	rr(t_push **stack_a, t_push **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
}

void	reverse_rotate_a(t_push **stack_a)
{
	t_push	*tmp;
	t_push	*dsp;
	int		len;

	len = ft_len_lst(*stack_a);
	if (len < 2)
		return ;
	if (len == 2)
	{
		swap_a(stack_a);
		return ;
	}
	dsp = *stack_a;
	while (dsp->next)
	{
		tmp = dsp;
		dsp = dsp->next;
	}
	dsp->next = (*stack_a);
	*stack_a = dsp;
	tmp->next = NULL;
}

void	reverse_rotate_b(t_push **stack_b)
{
	t_push	*tmp;
	t_push	*dsp;
	int		len;

	len = ft_len_lst(*stack_b);
	if (len < 2)
		return ;
	if (len == 2)
	{
		swap_b(stack_b);
		return ;
	}
	dsp = *stack_b;
	while (dsp->next)
	{
		tmp = dsp;
		dsp = dsp->next;
	}
	dsp->next = (*stack_b);
	*stack_b = dsp;
	tmp->next = NULL;
}

void	rrr(t_push **stack_a, t_push **stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
}
