/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_routine.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 09:22:04 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/30 19:13:48 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	swap_sb(t_vars *v)
{
	cmd_sb(v);
	cmd_pa(v);
	return (1);
}

static int	swap_sa(t_vars *v)
{
	cmd_pa(v);
	cmd_pa(v);
	cmd_sa(v);
	return (1);
}

static int	swap_ss(t_vars *v)
{
	cmd_pa(v);
	cmd_pa(v);
	cmd_ss(v);
	cmd_pa(v);
	cmd_pa(v);
	return (1);
}

int	swap_routine_check(t_vars *v)
{
	t_elem	*e[4];
	size_t	target;

	if (!v->b.head->next)
		return (0);
	target = v->b.high;
	e[0] = v->b.head->content;
	e[1] = v->b.head->next->content;
	if (e[1]->rank == target)
	{
		if (e[0]->rank + 1 == target)
		{
			if (v->b.head->next->next && v->b.head->next->next->next)
			{
				e[2] = v->b.head->next->next->content;
				e[3] = v->b.head->next->next->next->content;
				if (e[2]->rank + 3 == target && e[3]->rank + 2 == target)
					return (swap_ss(v));
			}
			return (swap_sa(v));
		}
		return (swap_sb(v));
	}
	return (0);
}
