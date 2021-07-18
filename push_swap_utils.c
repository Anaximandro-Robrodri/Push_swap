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
	nb *= sign;
	if (nb > INT_MAX || nb < INT_MIN)
		ft_error(0);
	return (nb);
}

/*t_push	*ft_lst_push_new(int argc, char **argv, t_push *lst)
{
	lst = malloc(sizeof(t_push));
	if (lst == 0)
		return (0);
	lst-> prev = NULL;
	lst-> num = argv[][];
	lst-> next = NULL;
	return (lst);
}*/
