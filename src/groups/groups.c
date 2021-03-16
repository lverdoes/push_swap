/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   groups.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 12:08:43 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/16 17:00:31 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	group_large(t_vars *v, t_node *stack, double val)
{
	t_elem	*e;
	double	min;
	double	max;

	e = stack->content;
	min = (double)v->total_size / 21 * val;
	max = (double)v->total_size / 21 * (val + 3);
	if (e->rank >= min && e->rank < max)
		return (1);
	return (0);
}

int	group_small(t_vars *v, t_node *stack, double val)
{
	t_elem	*e;
	double	min;
	double	max;

	e = stack->content;
	min = (double)v->total_size / 21 * val;
	max = (double)v->total_size / 21 * (val + 1);
	if (e->rank >= min && e->rank < max)
		return (1);
	return (0);
}

int	group_a(t_vars *v, t_node *stack)
{
	if (group_a1(v, stack))
		return (1);
	if (group_a2(v, stack))
		return (1);
	if (group_a3(v, stack))
		return (1);
	return (0);
}

int	group_b(t_vars *v, t_node *stack)
{
	if (group_b1(v, stack))
		return (1);
	if (group_b2(v, stack))
		return (1);
	if (group_b3(v, stack))
		return (1);
	return (0);
}

int	group_c(t_vars *v, t_node *stack)
{
	if (group_c1(v, stack))
		return (1);
	if (group_c2(v, stack))
		return (1);
	if (group_c3(v, stack))
		return (1);
	return (0);
}
