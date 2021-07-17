#include "push_swap.h"

void	ft_error(int i)
{
	write (1, "Error\n", 6);
	exit(i);
}

void	ft_analyze_arg (int pos, int i, char **argv)
{
		while (argv[i][pos])
		{
			if (!ft_isdigit(argv[i][pos]) && argv[i][pos] != ' ')
				ft_error(0);
			pos++;
		}
}

// En el futuro lo cambiamos para que lo almacene en la lista
int	ft_store_num (int i, int j, int minus, char **argv)
{
	while (ft_isdigit(argv[i][j]))
	{
		if (minus == -1)
		{
			write (1, "-", 1);
			minus = 1;
		}
		write (1, &argv[i][j++], 1);
	}
	write (1, "\n", 1);
	return (j);
}

int	ft_matrix_len(char **matrix)
{
	int	i;
	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

void	ft_is_one_arg(int pos, int i, char **argv)
{
	char	**split;

	split = ft_split(&argv[i][pos], ' ');
	if (ft_matrix_len(split) < 2)
		ft_error(0);
}

void	ft_check_argv(char **argv, int i)
{
	int	j;
	int	minus;

	j = 0;
	minus = 1;
	while (argv[i][j])
	{
		while ((argv[i][j] == '0' && (ft_isdigit(argv[i][j + 1]) || argv[i][j + 1] == '+' || argv[i][j + 1] == '-'))
			|| argv[i][j] == '+' || argv[i][j] == '-' || argv[i][j] == ' ')
		{
			if (argv[i][j] == '-')
				minus *= -1;
			j++;
		}
		if (!ft_isdigit(argv[i][j]))
			break ;
		ft_analyze_arg(j, i, argv);
		j = ft_store_num(i, j, minus, argv);
		minus = 1;
		j++;
	}
}

int	main (int argc, char **argv)
{
	int	i;
	int	j;
	int	minus;

	minus = 1;
	i = 1;
	if (argc > 2)
	{
		while (--argc)
		{
			j = 0;
			while ((argv[i][j] == '0' && (ft_isdigit(argv[i][j + 1]) || argv[i][j + 1] == '+' || argv[i][j + 1] == '-'))
				|| argv[i][j] == '+' || argv[i][j] == '-')
			{
				if (argv[i][j] == '-')
					minus *= -1;
				j++;
			}
			ft_analyze_arg(j, i, argv);
			ft_store_num(i, j, minus, argv);
			minus = 1;
			i++;
		}
	}
	else
	{
		ft_is_one_arg(0, i, argv);
		ft_check_argv(argv, i);
	}
	return(0);
}
