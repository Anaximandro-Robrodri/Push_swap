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
	tmp = *stack_a;
	dsp = tmp;
	while (dsp->next)
		dsp = dsp->next;
	dsp->next = tmp;
	*stack_a = dsp;
}
