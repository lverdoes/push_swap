/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   huge_part_6_10.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 18:45:19 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/30 18:47:51 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	split_huge_part_10(t_vars *v)
{
	while (!is_group_b(v, v->a.head))
	{
		if (group_n(v, v->a.head, 2, 2) || \
			group_n(v, v->a.head, 35, 35) || \
			group_n(v, v->a.head, 48, 48))
			cmd_ra(v);
		else
		{
			cmd_pb(v);
			if (group_n(v, v->b.head, 15, 15))
			{
				if (group_n(v, v->a.head, 2, 2) || \
					group_n(v, v->a.head, 35, 35) || \
					group_n(v, v->a.head, 48, 48))
					cmd_rr(v);
				else
					cmd_rb(v);
			}
		}
	}
}

void	split_huge_part_9(t_vars *v)
{
	while (!is_group_x(v, v->b.head))
	{
		if (group_n(v, v->b.head, 16, 16))
			cmd_rb(v);
		else
		{
			cmd_pa(v);
			if (group_n(v, v->a.head, 3, 3) || \
				group_n(v, v->a.head, 34, 34) || \
				group_n(v, v->a.head, 47, 47))
			{
				if (group_n(v, v->b.head, 16, 16))
					cmd_rr(v);
				else
					cmd_ra(v);
			}
		}
	}
}

void	split_huge_part_8(t_vars *v)
{
	while (!is_group_c(v, v->b.head))
	{
		if (group_n(v, v->b.head, 17, 17))
			cmd_rb(v);
		else
		{
			cmd_pa(v);
			if (group_n(v, v->a.head, 4, 4) || \
				group_n(v, v->a.head, 33, 33) || \
				group_n(v, v->a.head, 46, 46))
			{
				if (group_n(v, v->b.head, 17, 17))
					cmd_rr(v);
				else
					cmd_ra(v);
			}
		}
	}
}

void	split_huge_part_7(t_vars *v)
{
	while (!is_group_a(v, v->a.head))
	{
		if (group_n(v, v->a.head, 5, 5) || \
			group_n(v, v->a.head, 32, 32) || \
			group_n(v, v->a.head, 45, 45))
			cmd_ra(v);
		else
		{
			cmd_pb(v);
			if (group_n(v, v->b.head, 18, 18))
			{
				if (group_n(v, v->a.head, 5, 5) || \
					group_n(v, v->a.head, 32, 32) || \
					group_n(v, v->a.head, 45, 45))
					cmd_rr(v);
				else
					cmd_rb(v);
			}
		}
	}
}

void	split_huge_part_6(t_vars *v)
{
	while (!is_group_c(v, v->b.head))
	{
		if (group_n(v, v->b.head, 19, 19))
			cmd_rb(v);
		else
		{
			cmd_pa(v);
			if (group_n(v, v->a.head, 6, 6) || \
				group_n(v, v->a.head, 31, 31) || \
				group_n(v, v->a.head, 44, 44))
			{
				if (group_n(v, v->b.head, 19, 19))
					cmd_rr(v);
				else
					cmd_ra(v);
			}
		}
	}
}
