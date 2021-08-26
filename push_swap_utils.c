/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 13:29:35 by robrodri          #+#    #+#             */
/*   Updated: 2021/08/26 13:29:36 by robrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_space(char a)
{
	if ((a >= 9 && a <= 13) || a == ' ')
		return (1);
	return (0);
}

int	ft_is_sign(char a)
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

long	ft_atoi_plus(char *str)
{
	long			nb;
	int				sign;

	nb = 0;
	sign = 1;
	while (ft_is_space(*str))
		str++;
	if (ft_is_sign(*str))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit(*str))
		nb = (nb * 10) + (*str++ - '0');
	if (!ft_is_space(*str) && *str)
		ft_error(-1);
	nb *= sign;
	if (nb > INT_MAX || nb < INT_MIN)
		ft_error(-1);
	return (nb);
}
