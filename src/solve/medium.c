/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   medium.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/04 21:38:51 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/14 12:53:55 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static void push_in_range(t_stack *a)
{
	size_t const	range = 2;
	size_t			rank;

	rank = ((t_elem *)a->head->content)->rank;
	if (rank < a->low + range)
		cmd(PB, 1);
}

int	solve_medium(t_stack *a, t_stack *b)
{
	t_cmd	rot_dir;

	while (a->size > 4)
	{
		if (is_correct_rotation_order(a))
		{
			shortest_path(a, a->pos_low, 0);
			break;
		}
		else if (a->pos_low == 1)
			cmd(SA, 1);
		else
		{
			push_in_range(a);
			shortest_path(a, a->pos_low, 1);
		}
	}
	solve_small(a, b);
	push_back(a, b);
	return (0);
}
