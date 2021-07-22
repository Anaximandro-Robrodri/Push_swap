#include "push_swap.h"

void	swap_a(t_push	**stack_a)
{
	t_push	*tmp;

	if ((*stack_a)->next == NULL)
		return ;
	tmp = (*stack_a)->next->next;
	(*stack_a)->next->next = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_a)->next->next = tmp;
}
