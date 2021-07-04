/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_routine.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 09:22:04 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/04 10:49:11 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_routine(t_vars *v)
{
	t_elem	*a[4];
	t_elem	*b[4];

	if (!v->b.head->next || !v->a.head->next)
		return (0);
	a[0] = v->a.head->content;
	a[1] = v->a.head->next->content;
	b[0] = v->b.head->content;
	b[1] = v->b.head->next->content;
	if (a[0]->rank == v->a.low + 1 && a[1]->rank == v->a.low)
	{
		if (b[1]->rank == v->b.high && b[1]->rank == v->b.high)
		{
			cmd(SS, 1);
			return (1);
		}
		if (b[0]->rank + 1 == v->b.high || b[0]->rank == v->b.high)
		{
			cmd(SA, 1);
			return (1);
		}
	}
	if (b[1]->rank == v->b.high && b[1]->rank == v->b.high)
	{
		cmd(SB, 1);
		return (1);
	}
	return (0);
}
