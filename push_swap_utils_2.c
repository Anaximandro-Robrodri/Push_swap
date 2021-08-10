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

long	**get_chunky(int *array, int len, int size)
{
	long	**chunk;
	int		i;
	int		j;
	int 	c;

	chunk = (long **)malloc(sizeof(long *) * 11);
	i = 0;
	j = 0;
	while (i < 11)
	{
		c = 0;
		if (i == 10)
		{
			chunk[i] = malloc(sizeof(long) * (len - j + 1));
			size = len - j;
		}
		else
			chunk[i] = malloc(sizeof(long) * (size + 1));
		while (j < len && c < size)
		{
			chunk[i][c] = array[j];
			j++;
			c++;
		}
		chunk[i][c] = 2147483648;
		i++;
	}
	return (chunk);
}

int	check_chunky(long *array, int nbr)
{
	int		i;

	i = 0;
	while (array[i] != 2147483648)
	{
		printf("He entrado\n");
		if (array[i] == nbr)
			return (1);
		i++;
	}
	return (0);
}
