#include "push_swap.h"

int		find_half(t_push *stack, int num)
{
	int		len;
	t_push	*tmp;

	if (!stack)
		return (0);
	tmp = stack;
	len = ft_len_lst(stack) / 2;
	while (len--)
	{
		if (num == *tmp->num)
			return(1);
		tmp = tmp->next;
	}
	return (0);
}

int		find_high(t_push *stack)
{
	t_push	*aux;
	int		high;

	if (!stack)
		return (0);
	aux = stack;
	high = *aux->num;
	while (aux)
	{
		if (high < *aux->num)
			high = *aux->num;
		aux = aux->next;
	}
	return (high);
}

int		find_low(t_push	*stack)
{
	t_push	*aux;
	int		low;

	if (!stack)
		return (0);
	aux = stack;
	low = *aux->num;
	while (aux)
	{
		if (low > *aux->num)
			low = *aux->num;
		aux = aux->next;
	}
	return (low);
}

int		find_second_low(t_push *stack, int low)
{
	t_push	*aux;
	int 	second;

	if (!stack)
		return (0);
	aux = stack;
	if (*aux->num == low)
		second = *aux->next->num;
	else
		second = *aux->num;
	while (aux)
	{
		if ((second > *aux->num) && (*aux->num != low))
			second = *aux->num;
		aux = aux->next;
	}
	return (second);
}

int		ft_pivot(t_push *stack, int len)
{
	int		pivot;
	t_push	*tmp;

	if (!stack)
		return (0);
	tmp = stack;
	while(len--)
	{
		pivot = *tmp->num;
		tmp = tmp->next;
	}
	return (pivot);
}

int		check_success_b(t_push *b)
{
	t_push	*tmp;
	t_push	*aux;
	int		len;

	if (!b)
		return (1);
	len = ft_len_lst(b);
	aux = b;
	while (len--)
	{
		tmp = aux->next;
		while (tmp)
		{
			if (*aux->num < *tmp->num)
				return(0);
			tmp = tmp->next;
		}
		aux = aux->next;
	}
	return (1);
}

int	last_val(t_push *stack)
{
	t_push	*aux;

	aux = stack;
	while (aux->next)
		aux = aux->next;
	return (*aux->num);
}

int	not_in_stack(t_push *stack, long *chunk)
{
	t_push *aux;
	int		i;

	aux = stack;
	while (aux)
	{
		i = 0;
		while (chunk[i] != 2147483648)
		{
			if (*aux->num == chunk[i])
				return (1);
			i++;
		}
		aux = aux->next;
	}
	return (0);
}
