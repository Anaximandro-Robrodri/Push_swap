#include "push_swap.h"

int	ft_is_space (char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;

	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' \
			|| str[i] == '\f' || str[i] == '\v' || str[i] == '\r')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if ((str[i] == '+' || str[i] == '-') && (str[i + 1] == '+' || str[i + 1] == '-'))
			return (0);
		else (str[i] == '-')
		{
			sign *= (-1);
		}
		i++;
	}
	return (sign);
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
