#include "push_swap.h"

int		find_half(t_push *stack, int num)
{
	int		len;
	t_push	*tmp;

	tmp = stack;
	len = ft_len_lst(stack) / 2;
	while (len--)
	{
		if (num == tmp->num)
			return(1);
		tmp = tmp->next;
	}
	return (0);
}

int		find_high(t_push *stack)
{
	t_push	*aux;
	int		high;

	aux = stack;
	high = aux->num;
	while (aux)
	{
		if (high < aux->num)
			high = aux->num;
		aux = aux->next;
	}
	return (high);
}

int		find_low(t_push	*stack)
{
	t_push	*aux;
	int		low;

	aux = stack;
	low = aux->num;
	while (aux)
	{
		if (low > aux->num)
			low = aux->num;
		aux = aux->next;
	}
	return (low);
}

int		ft_pivot(t_push *stack, int len)
{
	int		pivot;
	t_push	*tmp;

	tmp = stack;
	while(len--)
	{
		pivot = tmp->num;
		tmp = tmp->next;
	}
	return (pivot);
}
