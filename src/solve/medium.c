/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   medium.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/04 21:38:51 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/04 10:23:12 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	solve_medium(t_vars *v, size_t limit)
{
	size_t	scope;
	t_elem	*e;

	while (v->a.size > MEDIUM)
	{
		shortest_path(&v->a, v->a.pos_low, 1);
		scope = v->a.low + limit;
		e = v->a.head->content;
		if (e->rank <= scope)
			cmd(PB, 1);
	}
	return (solve_small(v));
}
