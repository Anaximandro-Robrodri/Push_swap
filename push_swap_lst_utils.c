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
