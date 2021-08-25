#include "push_swap.h"

int		find_half(t_push *stack, int num)
{
	int		len;
	t_push	*tmp;

	if (!stack)
		return (0);
	tmp = stack;
	len = (ft_len_lst(stack) / 2);
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


static int	get_len(t_push *aux, int num)
{
	int	ret;

	ret = 0;
	while (aux)
	{
		if(*aux->num == num)
			break ;
		aux = aux->next;
		ret++;
	}
	return(ret);
}

int	smart_rotate(int high, int low, t_push *stack)
{
	t_push	*aux;
	int	i;
	int	j;
	int	len;

	aux = stack;
	i = get_len(aux, high);
	j = get_len(aux, low);
	len = ft_len_lst(stack);
	if (j < len && j < len / 2 && j < i - len)
		return (1);
	else
		return(0);
	
}
