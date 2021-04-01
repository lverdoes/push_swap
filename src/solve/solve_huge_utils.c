/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_huge_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/01 11:46:05 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/01 17:39:13 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int group_n(t_vars *v, t_node *stack, size_t low, size_t high)
{
	t_elem	*e;
	double	top;
	double	bottom;

	e = stack->content;
	top = (double)v->total_size / 49 * high;
	bottom = (double)v->total_size / 49 * (low - 1);
	if (e->rank < top && e->rank >= bottom)
		return (1);
	return (0);
}

int	is_group_x(t_vars *v, t_node *stack)
{
	if (group_n(v, stack, 10, 10))
		return (1);
	if (group_n(v, stack, 23, 23))
		return (1);
	if (group_n(v, stack, 27, 27))
		return (1);
	if (group_n(v, stack, 40, 40))
		return (1);
	return (0);
}

int	is_group_a(t_vars *v, t_node *stack)
{
	if (group_n(v, stack, 7, 9))
		return (1);
	if (group_n(v, stack, 11, 11))
		return (1);
	if (group_n(v, stack, 20, 22))
		return (1);
	if (group_n(v, stack, 26, 26))
		return (1);
	if (group_n(v, stack, 28, 30))
		return (1);
	if (group_n(v, stack, 39, 39))
		return (1);
	if (group_n(v, stack, 41, 43))
		return (1);
	return (0);
}

int	is_group_b(t_vars *v, t_node *stack)
{
	if (group_n(v, stack, 4, 6))
		return (1);
	if (group_n(v, stack, 12, 12))
		return (1);
	if (group_n(v, stack, 17, 19))
		return (1);
	if (group_n(v, stack, 25, 25))
		return (1);
	if (group_n(v, stack, 31, 33))
		return (1);
	if (group_n(v, stack, 38, 38))
		return (1);
	if (group_n(v, stack, 44, 45))
		return (1);
	return (0);
}

int	is_group_c(t_vars *v, t_node *stack)
{
	if (group_n(v, stack, 1, 3))
		return (1);
	if (group_n(v, stack, 13, 16))
		return (1);
	if (group_n(v, stack, 24, 24))
		return (1);
	if (group_n(v, stack, 34, 37))
		return (1);
	if (group_n(v, stack, 47, 49))
		return (1);
	return (0);
}
