/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   groups.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 12:08:43 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/10 00:29:10 by lverdoes      ########   odam.nl         */
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
	if (group_large(v, stack, 18))
		return (1);
	return (0);
}

int	group_b(t_vars *v, t_node *stack)
{
	if (group_large(v, stack, 15))
		return (1);
	if (group_large(v, stack, 12))
		return (1);
	if (group_small(v, stack, 5))
		return (1);
	if (group_small(v, stack, 4))
		return (1);
	if (group_small(v, stack, 1))
		return (1);
	return (0);
}

int	group_c(t_vars *v, t_node *stack)
{
	if (group_large(v, stack, 9))
		return (1);
	if (group_large(v, stack, 6))
		return (1);
	if (group_small(v, stack, 3))
		return (1);
	if (group_small(v, stack, 2))
		return (1);
	if (group_small(v, stack, 0))
		return (1);
	return (0);
}
