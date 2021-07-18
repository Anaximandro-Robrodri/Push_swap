#include "push_swap.h"

int	ft_is_space (char a)
{
	if ((a >= 9 && a <= 13) || a == ' ')
		return (1);
	return (0);
}

int	ft_is_sign (char a)
{
	if (a == '+' || a == '-')
		return (1);
	return (0);
}

int	ft_split_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long	ft_atoi_plus (char *str)
{
	long			nb;
	int				sign;

	nb = 0;
	sign = 1;
	while (ft_is_space(*str))
		str++;
	while (ft_is_sign(*str))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit(*str))
		nb = nb * 10 + *str++ - '0';
	if (!ft_is_space(*str) && *str)
		ft_error(0);
	nb *= sign;
	if (nb > INT_MAX || nb < INT_MIN)
		ft_error(0);
	return (nb);
}

// Función de Cristian, permite desplazar el atoi después de guardar el Num
// En principio no la necestio porque uso el split para guardar el Num
// Guardar por si acaso.
/*char	*ft_move_atoi (char *str)
{
	while (ft_is_space(*str))
		str++;
	while (ft_is_sign(*str))
		str++;
	while (ft_isdigit(*str))
		str++;
	return(str);
}*/
