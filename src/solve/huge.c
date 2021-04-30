/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   huge.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 20:57:26 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/30 18:46:16 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	split_huge_part_finish(t_vars *v)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->a.size;
	while (i < size)
	{
		if (group_n(v, v->a.head, 37, 49))
			cmd_ra(v);
		else
		{
			cmd_pb(v);
			if (group_n(v, v->b.head, 1, 13))
			{
				if (group_n(v, v->a.head, 37, 49))
				{
					cmd_rr(v);
					i++;
				}
				else
					cmd_rb(v);
			}
		}
		i++;
	}
}

static void	split_huge_part_11(t_vars *v)
{
	while (!is_group_x(v, v->b.head))
	{
		if (group_n(v, v->b.head, 14, 14))
			cmd_rb(v);
		else
		{
			cmd_pa(v);
			if (group_n(v, v->a.head, 1, 1) || \
				group_n(v, v->a.head, 36, 36) || \
				group_n(v, v->a.head, 49, 49))
			{
				if (group_n(v, v->b.head, 14, 14))
					cmd_rr(v);
				else
					cmd_ra(v);
			}
		}
	}
}

int	solve_huge(t_vars *v)
{
	split_huge_part_xabc(v);
	split_huge_part_x(v);
	split_huge_part_3(v);
	split_huge_part_4(v);
	split_huge_part_5(v);
	split_huge_part_6(v);
	split_huge_part_7(v);
	split_huge_part_8(v);
	split_huge_part_9(v);
	split_huge_part_10(v);
	split_huge_part_11(v);
	split_huge_part_finish(v);
	solve_medium(v, 2);
	return (1);
}
