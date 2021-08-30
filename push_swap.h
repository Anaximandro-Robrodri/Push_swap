/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 13:28:51 by robrodri          #+#    #+#             */
/*   Updated: 2021/08/30 11:08:45 by robrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_push
{
	int				num;
	struct s_push	*next;
}	t_push;

typedef struct s_pivot
{
	int		pivot;
	int		quarter;
	int		next_q;
}	t_pivot;

int		ft_is_space(char a);
int		ft_is_sign(char a);
int		ft_split_len(char **str);
long	ft_atoi_plus(char *str);
void	ft_error(int i);
int		not_good_argv(int argc, char **argv);
int		ft_error_control(int argc, char **argv);

//////////////////////////////////////////////////////////////
// LST FUNCTIONS

t_push	*create_new_node(int num);
int		ft_len_lst(t_push *stack_a);
void	ft_check_equals(t_push *stack_a);
void	ft_store_args(t_push **stack, int num);
int		check_success(t_push *stack_a);
int		smart_rotate(int high, int low, t_push *stack);
int		check_left(t_push *a, int pivot);
void	free_list(t_push **stack);

/////////////////////////////////////////////////////////////
//MOVEMENTS

void	swap(t_push **stack, int i);
void	ss(t_push **stack_a, t_push **stack_b);
void	rotate(t_push **stack, int i);
void	rr(t_push **stack_a, t_push **stack_b);
void	reverse_rotate(t_push **stack, int i);
void	rrr(t_push **stack_a, t_push **stack_b);
void	push_b(t_push **stack_a, t_push **stack_b);
void	push_a(t_push **stack_a, t_push **stack_b);

//////////////////////////////////////////////////////////////
//OPERATIONS ORDER
void	ft_order(t_push **stack_a, t_push **stack_b);
void	ft_three_num(t_push **a);
void	ft_long_num(t_push **a, t_push **b);
int		find_high(t_push *stack);
int		find_low(t_push	*stack);
int		find_half(t_push *stack, int num);
int		*ft_sort_int_tab(int *tab, int size);
int		*bubble(t_push *s);
void	ft_sort_hundred(t_push **a, t_push **b, int pivot);
void	ft_quarter(t_push **a, t_push **b, int i, int *array);
void	sort_b(t_push **a, t_push **b);
int		get_pivot(int *array, int i, int len);
int		get_quarter(int *array, int i, int len);
int		is_left(t_push *stack, int pivot, int quarter);
int		is_left_high(t_push *stack, int pivot, int quarter);
void	init_pivot_points(t_pivot *p, int *array, int i, t_push *a);
void	first_cycle(t_pivot p, t_push **a, t_push **b);
void	second_cycle(t_pivot p, t_push **a, t_push **b);

#endif
