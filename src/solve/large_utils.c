/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   large_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 09:13:21 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/30 09:15:35 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	split_large_part_5(t_vars *v)
{
	while (!large_group_n(v, v->b.head, 6))
	{
		if (large_group_n(v, v->b.head, 1))
			cmd_rb(v);
		else
		{
			cmd_pa(v);
			if (large_group_n(v, v->a.head, 11))
			{
				if (large_group_n(v, v->b.head, 1))
					cmd_rr(v);
				else
					cmd_ra(v);
			}
		}
	}
}

void	split_large_part_4(t_vars *v)
{
	while (!large_group_n(v, v->a.head, 8))
	{
		if (large_group_n(v, v->a.head, 10))
			cmd_ra(v);
		else
		{
			cmd_pb(v);
			if (large_group_n(v, v->b.head, 2))
			{
				if (large_group_n(v, v->a.head, 10))
					cmd_rr(v);
				else
					cmd_rb(v);
			}
		}
	}
}

void	split_large_part_3(t_vars *v)
{
	while (!large_is_group_a(v, v->a.head))
	{
		if (large_group_n(v, v->a.head, 9))
			cmd_ra(v);
		else
		{
			cmd_pb(v);
			if (large_group_n(v, v->b.head, 3))
			{
				if (large_group_n(v, v->a.head, 9))
					cmd_rr(v);
				else
					cmd_rb(v);
			}
		}
	}
}

void	split_large_part_2(t_vars *v)
{
	while (!large_group_n(v, v->b.head, 5))
	{
		if (large_group_n(v, v->b.head, 4))
			cmd_rb(v);
		else
		{
			cmd_pa(v);
			if (large_group_n(v, v->a.head, 8))
			{
				if (large_group_n(v, v->b.head, 4))
					cmd_rr(v);
				else
					cmd_ra(v);
			}
		}
	}
}

void	split_large_part_1(t_vars *v)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->a.size;
	while (i < size)
	{
		if (large_is_group_a(v, v->a.head))
			cmd_ra(v);
		else
		{
			cmd_pb(v);
			if (large_group_n(v, v->b.head, 5))
			{
				if (large_is_group_a(v, v->a.head))
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
