/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   large.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 15:35:30 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/04 12:33:53 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	split_large_part_5(t_vars *v)
{
	while (!large_group_n(v, v->b.head, 6))
	{
		if (large_group_n(v, v->b.head, 1))
			cmd(RB, 1);
		else
		{
			cmd(PA, 1);
			if (large_group_n(v, v->a.head, 11))
			{
				if (large_group_n(v, v->b.head, 1))
					cmd(RR, 1);
				else
					cmd(RA, 1);
			}
		}
	}
}

static void	split_large_part_4(t_vars *v)
{
	while (!large_group_n(v, v->a.head, 8))
	{
		if (large_group_n(v, v->a.head, 10))
			cmd(RA, 1);
		else
		{
			cmd(PB, 1);
			if (large_group_n(v, v->b.head, 2))
			{
				if (large_group_n(v, v->a.head, 10))
					cmd(RR, 1);
				else
					cmd(RB, 1);
			}
		}
	}
}

static void	split_large_part_3(t_vars *v)
{
	while (!large_is_group_a(v, v->a.head))
	{
		if (large_group_n(v, v->a.head, 9))
			cmd(RA, 1);
		else
		{
			cmd(PB, 1);
			if (large_group_n(v, v->b.head, 3))
			{
				if (large_group_n(v, v->a.head, 9))
					cmd(RR, 1);
				else
					cmd(RB, 1);
			}
		}
	}
}

static void	split_large_part_2(t_vars *v)
{
	while (!large_group_n(v, v->b.head, 5))
	{
		if (large_group_n(v, v->b.head, 4))
			cmd(RB, 1);
		else
		{
			cmd(PA, 1);
			if (large_group_n(v, v->a.head, 8))
			{
				if (large_group_n(v, v->b.head, 4))
					cmd(RR, 1);
				else
					cmd(RA, 1);
			}
		}
	}
}

static void	split_large_part_1(t_vars *v)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->a.size;
	while (i < size)
	{
		if (large_is_group_a(v, v->a.head))
			cmd(RA, 1);
		else
		{
			cmd(PB, 1);
			if (large_group_n(v, v->b.head, 5))
			{
				if (large_is_group_a(v, v->a.head))
				{
					cmd(RR, 1);
					i++;
				}
				else
					cmd(RB, 1);
			}
		}
		i++;
	}
}

int	solve_large(t_vars *v)
{
	split_large_part_1(v);
	split_large_part_2(v);
	split_large_part_3(v);
	split_large_part_4(v);
	split_large_part_5(v);
	solve_medium(v, 2);
	return (1);
}
