#include "push_swap.h"

void	ft_check_parameter (char **argv)
{
	int		len;
	char	*aux;

	len = ft_strlen(*argv);
	if (len < 2)
	{
		write (1, "error\n", 6);
		return ;
	}
	else
	{
		aux = *argv;
		while (len--)
		{
			if (!ft_isdigit(*aux) && *aux != ' ')
				break ;
			while (*aux == ' ')
				aux++;
			write (1, &*aux, 1);
			write (1, "\n", 1);
			aux++;
		}
	}
}

int	main (int argc, char **argv)
{
	if (argc > 2)
	{
		while (--argc)
		{
			argv++;
			if (ft_strlen(*argv) < 2)
			{
				if (!ft_isdigit(**argv) && **argv != ' ')
					break ;
				while (**argv == '0')
					argv++;
				write (1, &**argv, 1);
				write (1, "\n", 1);
			}
			else
				ft_check_parameter (argv);
		}
	}
	else
		ft_check_parameter (++argv);
	return(0);
}
