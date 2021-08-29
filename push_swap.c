/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 13:28:44 by robrodri          #+#    #+#             */
/*   Updated: 2021/08/26 14:40:30 by robrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int i)
{
	write (1, "Error\n", 6);
	exit(i);
}

int	ft_error_control(int i, char **argv)
{
	int	pos;

	pos = 0;
	while (argv[i][pos])
	{
		if (!ft_isdigit(argv[i][pos]) && !ft_is_space(argv[i][pos])
				&& !ft_is_sign(argv[i][pos]))
			return(0);
		if (ft_is_sign(argv[i][pos]))
		{
			if (!ft_isdigit(argv[i][pos + 1]) || !argv[i][pos + 1])
				return(0);
		}
		pos++;
	}
	return(1);
}

void	ft_store_args(t_push **stack, int num)
{
	t_push	*tmp;

	if (*stack == NULL)
		*stack = create_new_node(num);
	else
	{
		tmp = *stack;
		*stack = create_new_node(num);
		(*stack)->next = tmp;
	}
}

static	t_push	*ft_args(int argc, char **argv, t_push *stack_a)
{
	char	**split;
	int	len;
	int	num;

	while (--argc)
	{
		split = ft_split(argv[argc], ' ');
		len = ft_split_len(split);
		while (len--)
		{
			num = ft_atoi_plus(split[len]);
			free(split[len]);
			ft_store_args(&stack_a, num);
		}
		free(split);
	}
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_push	*stack_a;
	t_push	*stack_b;

	if (argc < 2)
		exit (-1);
	stack_a = NULL;
	stack_b = NULL;
	if (!not_good_argv(argc, argv))
		ft_error(-1);
	stack_a = ft_args(argc, argv, stack_a);
	if (ft_len_lst(stack_a) < 2)
		return (0);
	ft_check_equals(stack_a);
	ft_order(&stack_a, &stack_b);
	free_list(&stack_a);
	return (0);
}
