/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   large.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 15:35:30 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/30 17:33:32 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	large_group_n(t_vars *v, t_node *stack, size_t num)
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

int	large_is_group_a(t_vars *v, t_node *stack)
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

int	solve_large(t_vars *v)
{
	split_large_part_1(v);
	split_large_part_2(v);
	split_large_part_3(v);
	split_large_part_4(v);
	split_large_part_5(v);
	solve_medium(v, 2);
	return (1);
}
