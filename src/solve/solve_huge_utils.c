/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_huge_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/01 11:46:05 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/01 13:54:00 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>



int group_n(t_vars *v, t_node *stack, size_t low, size_t high)
{
	t_elem	*e;
	double	top;
	double	bottom;

	e = stack->content;
	top = (double)v->total_size / 31 * high;
	bottom = (double)v->total_size / 31 * (low - 1);
	if (e->rank < top && e->rank >= bottom)
		return (1);
	return (0);
}

int	is_group_a(t_vars *v, t_node *stack)
{
	if (group_n(v, stack, 1, 1))
		return (1);
	if (group_n(v, stack, 6, 6))
		return (1);
	if (group_n(v, stack, 7, 7))
		return (1);
	if (group_n(v, stack, 8, 8))
		return (1);
	if (group_n(v, stack, 13, 13))
		return (1);
	if (group_n(v, stack, 14, 14))
		return (1);
	if (group_n(v, stack, 17, 17))
		return (1);
	if (group_n(v, stack, 14, 14))
		return (1);
	if (group_n(v, stack, 18, 18))
		return (1);
	if (group_n(v, stack, 19, 19))
		return (1);
	if (group_n(v, stack, 24, 24))
		return (1);
	if (group_n(v, stack, 25, 25))
		return (1);
	if (group_n(v, stack, 26, 26))
		return (1);
	if (group_n(v, stack, 31, 31))
		return (1);
	return (0);
}

int	is_group_b(t_vars *v, t_node *stack)
{
	if (group_n(v, stack, 2, 2))
		return (1);
	if (group_n(v, stack, 5, 5))
		return (1);
	if (group_n(v, stack, 9, 9))
		return (1);
	if (group_n(v, stack, 12, 12))
		return (1);
	if (group_n(v, stack, 16, 16))
		return (1);
	if (group_n(v, stack, 20, 20))
		return (1);
	if (group_n(v, stack, 23, 23))
		return (1);
	if (group_n(v, stack, 27, 27))
		return (1);
	if (group_n(v, stack, 30, 30))
		return (1);
	return (0);
}

int	is_group_c(t_vars *v, t_node *stack)
{
	if (group_n(v, stack, 3, 3))
		return (1);
	if (group_n(v, stack, 4, 4))
		return (1);
	if (group_n(v, stack, 10, 10))
		return (1);
	if (group_n(v, stack, 11, 11))
		return (1);
	if (group_n(v, stack, 15, 15))
		return (1);
	if (group_n(v, stack, 21, 21))
		return (1);
	if (group_n(v, stack, 22, 22))
		return (1);
	if (group_n(v, stack, 28, 28))
		return (1);
	if (group_n(v, stack, 29, 29))
		return (1);
	return (0);
}
