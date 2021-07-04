/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shortest_path.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/04 10:43:57 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/04 10:44:04 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_dir(size_t rotations, size_t limit, t_cmd dir)
{
	if (limit && limit < rotations)
		rotations = limit;
	cmd(dir, rotations);
}

int	shortest_path(t_stack *s, size_t pos, size_t limit)
{
	size_t	rotations_r;
	size_t	rotations_rr;
	t_cmd	dir_rr;
	t_cmd	dir_r;

	if (s->id == STACK_A)
	{
		dir_rr = RRA;
		dir_r = RA;
	}
	else
	{
		dir_rr = RRB;
		dir_r = RB;
	}
	rotations_rr = s->size - pos;
	rotations_r = pos;
	if (rotations_rr < rotations_r)
		rotate_dir(rotations_rr, limit, dir_rr);
	else
		rotate_dir(rotations_r, limit, dir_r);
	return (0);
}
