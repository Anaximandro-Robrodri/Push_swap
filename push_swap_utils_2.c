#include "push_swap.h"

int *ft_sort_int_tab(int *tab, int size)
{
    int x;
    int y;
    int aux;

    x = 0;
    while (x <= size - 1)
    {
        y = 0;
        while (y <= size - 2)
        {
            if (tab[y] > tab[x])
            {
                aux = tab[x];
                tab[x] = tab[y];
                tab[y] = aux;
            }
            y++;
        }
        x++;
    }
    return (tab);
}

int *bubble(t_push *s)
{
    t_push  *aux;
    int     *array;
    int     i;

    aux = s;
    i = 0;
    array = malloc(sizeof(int) * ft_len_lst(s));
    while (aux)
    {
        array[i++] = *aux->num;
        aux = aux->next;
    }
	array = ft_sort_int_tab(array, i);
    return (array);
}

static void	choose_rotate(t_push **b, int num)
{
	if (find_half(*b, num))
		rotate(b, 0);
	else
		reverse_rotate(b, 0);
}

void	sort_b(t_push **a, t_push **b)
{
	int	low;
	
	while(ft_len_lst(*b))
	{
		low = find_low(*b);
		if(*(*b)->num == find_high(*b)
			|| *(*b)->num == low)
		{
			push_a(a, b);
			if (*(*a)->num == low)
				rotate(a, 1);
		}
		else if (smart_rotate(find_high(*b), low, *b))
			choose_rotate(b, low);
		else
			choose_rotate(b, find_high(*b));
	}
}
