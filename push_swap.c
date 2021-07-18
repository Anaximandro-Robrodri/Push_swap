#include "push_swap.h"

void	ft_error(int i)
{
	write (1, "Error\n", 6);
	exit(i);
}

static	void	ft_error_control(int i, char **argv)
{
	int	pos;
	int	flag;

	pos = 0;
	flag = 0;
	while (argv[i][pos])
	{
		if (!ft_isdigit(argv[i][pos]) && !ft_is_space(argv[i][pos]) 
				&& !ft_is_sign(argv[i][pos]))
				ft_error(0);
		if (ft_isdigit(argv[i][pos]))
			flag = 1;
		pos++;
	}
	if (flag == 0)
		ft_error(0);
}

// Cambiar para que lo guarde en la lista
static	void	ft_store_arg(int num)
{
//	ft_lst_push_new(num);
	printf("%d\n", num);
}

static	void	ft_args(int argc, char **argv)
{
	int		num;
	char	**split;
	int		len;

	while (--argc)
	{
		ft_error_control(argc, argv);
		split = ft_split(argv[argc], ' ');
		len = ft_split_len(split);
		if (len > 1)
		{
			while (len--)
			{
				num = ft_atoi_plus(split[len]);
				ft_store_arg(num);
			}
		}
		else
		{
			num = ft_atoi_plus(argv[argc]);
			ft_store_arg(num);
		}
	}
}

int	main (int argc, char **argv)
{
//	t_push	stack_a;
//	t_push	stack_b;

	if (argc < 2)
		ft_error(0);
	ft_args(argc, argv);
	return(0);
}
