#include "push_swap.h"

//Aqui vamos a escribir las reglas, es decir, todos los movimientos
//que podemos ejecutar



// Intercambiar las 2 PRIMERAS posiciones de la pila A
void	swap_a(int **a)
{
	int	aux;

	if (!a || ft_strlen(*a) < 2)
		return ;
	aux = a[0];
	a[0] = a[1];
	a[1] = aux;
}

// Intercambiar las 2 PRIMERAS posiciones de la pila B
void	swap_b(int **b)
{
	int	aux;

	if (!a || ft_strlen(*b) < 2)
		return ;
	aux = b[0];
	b[0] = b[1];
	b[1] = aux;
}

// Ejecuta SWAP_A y SWAP_B a la vez
void	ss(int ***a, int ***b)
{
	swap_a(**&a);
	swap_b(**&b);
}

// Invierte  todos los elementos del stack A
void	rotate_a(int **a)
{
	int 	len;
	int		aux;
	int		i;

	len = (ft_strlen(*a) / 2);
	i = 0;
	while (i < len)
	{
		aux = a[i];
		a[i] = a[(len * 2) - i - 1];
		a[(len * 2) - i - 1] = aux;
		i++;
	}
}

// Invierte todo los elementos del stack B
void	rotate_b(int **b)
{
	int		len;
	int		aux;
	int		i;

	len = (ft_strlen(*b) / 2);
	i = 0;
	while (i < len)
	{
		aux = b[i];
		b[i] = b[(len * 2) - i - 1];
		b[(len * 2) -i - 1] = aux;
	}
}

// Ejectua ROTATE_A Y ROTATE_B a la vez
void	rr(int ***a, int ***b)
{
	rotate_a(**&a);
	rotate_b(**&b);
}

// Desplaza en 1 hacia abajo los elementos de a. El ultimo pasa a ser el primero;
void	reverse_rotate_a(int **a)
{
	int		len;
	int		aux;
	int		aux2;
	int		i;

	len = (ft_strlen(*a));
	i = 1;
	aux = a[0];
	a[0] = a[len - 1];
	while (i < len - 2)
	{
		aux2 = a[i];
		a[i] = aux;
		i++;
	}
}

// Desplaza en 1 hacia abajo los elementos de b. El ultimo pasa a ser el primero
void	reverse_rotate_b(int **b)
{
	int		len;
	int		aux;
	int		aux2;
	int		i;

	len = ft_strlen(*b);
	i = 1;
	aux = b[0];
	b[0] = b[len - 1];
	while (i < len - 2)
	{
		aux2 = b[i];
		b[i] = aux;
		i++;
	}
}

// Ejecuta REVERSE_ROTATE_A Y REVERSE_ROTATE_B a la vez
void	rrr(int ***a, int ***b)
{
	reverse_rotate_a(**&a);
	reverse_rotate_b(**&b);
}
