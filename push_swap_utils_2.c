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

int	**get_chunky(int *array, int len)
{
	int	**chunk;
	int	i;
	int	j;
	int c;

	chunk = (int **)malloc(sizeof(int *) * 10);
	i = 0;
	j = 0;
	while (i < 10)
	{
		c = 0;
		chunk[i] = malloc(sizeof(int) * 10);
		while (j < len && c < 10)
		{
			chunk[i][c] = array[j];
			j++;
			c++;
		}
		i++;
	}
	return (chunk);
}
