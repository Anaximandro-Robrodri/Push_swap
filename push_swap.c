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

static	void	ft_args(int argc, char **argv, t_push *stack_a)
{
	int		num;
	char	**split;
	int		len;

	while (--argc)
	{
		ft_error_control(argc, argv);
		split = ft_split(argv[argc], ' ');
		len = ft_split_len(split);
		while (len--)
		{
			num = ft_atoi_plus(split[len]);
			free(split[len]);
			stack_a->num = num;
			printf("%d\n", stack_a->num);
		}
		free(split);
	}
}

int	main (int argc, char **argv)
{
	t_push	stack_a;
//	t_push	stack_b;

	if (argc < 2)
		ft_error(0);
	ft_args(argc, argv, &stack_a);
	system("leaks a.out");
	return(0);
}
