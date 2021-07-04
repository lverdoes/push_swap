/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   large_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 09:13:21 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/03 15:09:34 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	large_group_n(t_vars *v, t_list *stack, size_t num)
{
	t_elem	*e;
	double	top;
	double	bottom;

	e = stack->content;
	top = (double)v->total_size / 11 * num;
	bottom = (double)v->total_size / 11 * (num - 1);
	if (e->rank < top && e->rank >= bottom)
		return (1);
	return (0);
}

int	large_is_group_a(t_vars *v, t_list *stack)
{
	if (large_group_n(v, stack, 1))
		return (1);
	if (large_group_n(v, stack, 2))
		return (1);
	if (large_group_n(v, stack, 7))
		return (1);
	if (large_group_n(v, stack, 10))
		return (1);
	if (large_group_n(v, stack, 11))
		return (1);
	return (0);
}
