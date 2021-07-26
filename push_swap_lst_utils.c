#include "push_swap.h"

t_push	*create_new_node(int num)
{
	t_push	*node;

	node = malloc(sizeof(t_push));
	if (node == 0)
		return (0);
	node->num = num;
	node->next = NULL;
	return (node);
}

// Función para comprobar que todo está ok. Borrar más adelante / Sustituir por write
void	print_list(t_push *stack_a)
{
	while (stack_a)
	{
		printf("%d\n", stack_a->num);
		stack_a = stack_a->next;
	}
}

int	ft_len_lst(t_push *stack_a)
{
	t_push	*aux;
	int		i;

	i = 0;
	aux = stack_a;
	while (aux)
	{
		aux = aux->next;
		i++;
	}
	return (i);
}

void	ft_check_equals(t_push *stack_a)
{
	t_push	*tmp;
	int		len;

	len = ft_len_lst(stack_a);
	while (len--)
	{
		tmp = stack_a->next;
		while (tmp)
		{
			if (stack_a->num == tmp->num)
				ft_error(0);
			tmp = tmp->next;
		}
		stack_a = stack_a->next;
	}
}

int	check_success(t_push *stack_a)
{
	t_push	*tmp;
	t_push	*aux;
	int		len;

	if (!stack_a)
		return (1);
	len = ft_len_lst(stack_a);
	aux = stack_a;
	while (len--)
	{
		tmp = aux->next;
		while (tmp)
		{
			if (aux->num > tmp->num)
				return(0);
			tmp = tmp->next;
		}
		aux = aux->next;
	}
	return (1);
}
