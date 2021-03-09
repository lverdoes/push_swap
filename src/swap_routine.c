/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_routine.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 08:47:15 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/09 16:20:43 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	swap_routine(t_vars *v)
{
	t_elem	*a;
	t_elem	*a_2nd;
	t_elem	*a_3;
	t_elem	*b;
	t_elem	*b_2nd;

	if (v->a)
	{
		a = v->a->content;
		if (v->a->next)
			a_2nd = v->a->next->content;
	}
	if (v->b)
	{
		b = v->b->content;
		if (v->b->next)
			b_2nd = v->b->next->content;
	}
	if (v->a && v->a->next && a->rank == a_2nd->rank + 1)
	{
		a_3 = v->a->next->next->content;
		if (v->b && v->b->next && b->rank + 1 == b_2nd->rank)
			return (cmd_ss(v));
		return (cmd_sa(v));
	}
	if (v->b && v->b->next && b->rank + 1 == b_2nd->rank)
		return (cmd_sb(v));
	return (1);
}
