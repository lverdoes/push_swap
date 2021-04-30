/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   huge_part_1_5.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 18:45:21 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/30 18:48:02 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	split_huge_part_5(t_vars *v)
{
	while (!is_group_b(v, v->b.head))
	{
		if (group_n(v, v->b.head, 20, 20))
			cmd_rb(v);
		else
		{
			cmd_pa(v);
			if (group_n(v, v->a.head, 7, 7) || \
				group_n(v, v->a.head, 30, 30) || \
				group_n(v, v->a.head, 43, 43))
			{
				if (group_n(v, v->b.head, 20, 20))
					cmd_rr(v);
				else
					cmd_ra(v);
			}
		}
	}
}

void	split_huge_part_4(t_vars *v)
{
	while (!is_group_x(v, v->a.head))
	{
		if (group_n(v, v->a.head, 8, 8) || \
			group_n(v, v->a.head, 29, 29) || \
			group_n(v, v->a.head, 42, 42))
			cmd_ra(v);
		else
		{
			cmd_pb(v);
			if (group_n(v, v->b.head, 21, 21))
			{
				if (group_n(v, v->a.head, 8, 8) || \
					group_n(v, v->a.head, 29, 29) || \
					group_n(v, v->a.head, 42, 42))
					cmd_rr(v);
				else
					cmd_rb(v);
			}
		}
	}
}

void	split_huge_part_3(t_vars *v)
{
	while (!is_group_b(v, v->b.head))
	{
		if (group_n(v, v->b.head, 22, 22))
			cmd_rb(v);
		else
		{
			cmd_pa(v);
			if (group_n(v, v->a.head, 9, 9) || \
				group_n(v, v->a.head, 28, 28) || \
				group_n(v, v->a.head, 41, 41))
			{
				if (group_n(v, v->b.head, 22, 22))
					cmd_rr(v);
				else
					cmd_ra(v);
			}
		}
	}
}

void	split_huge_part_x(t_vars *v)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->a.size;
	while (i < size)
	{
		if (is_group_x(v, v->a.head) && !group_n(v, v->a.head, 23, 23))
			cmd_ra(v);
		else
		{
			cmd_pb(v);
			if (group_n(v, v->b.head, 23, 23))
			{
				if (is_group_x(v, v->a.head) && !group_n(v, v->a.head, 23, 23))
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

void	split_huge_part_xabc(t_vars *v)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->a.size;
	while (i < size)
	{
		if (is_group_a(v, v->a.head) || is_group_x(v, v->a.head))
			cmd_ra(v);
		else
		{
			cmd_pb(v);
			if (is_group_c(v, v->b.head))
			{
				if (is_group_a(v, v->a.head) || is_group_x(v, v->a.head))
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
