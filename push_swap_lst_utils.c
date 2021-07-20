#include "push_swap.h"

t_push	*create_new_node(int num)
{
	t_push	*node;

	node = malloc(sizeof(t_push));
	if (node == 0)
		return (0);
	node->num = num;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	free_list(t_push **head)
{
   t_push *tmp;

   while (*head)    
   	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
    }
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
	int	*used;
	int	i;
	int	pos;

	used = ft_calloc(10, sizeof(int));
	i = 0;
	while (stack_a)
	{
		if (!used[0])
			used[i] = stack_a->num;
		else
		{
			pos = 0;
			while (used[pos])
			{
				if (stack_a->num == used[pos])
					ft_error(0);
				pos++;
			}
			used[i] = stack_a->num;
		}
		i++;
		stack_a = stack_a->next;
	}
	free(used);
}
