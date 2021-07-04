/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   huge.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 20:57:26 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/03 17:51:06 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	split_huge_part_finish(t_vars *v)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->a.size;
	while (i < size)
	{
		if (group_n(v, v->a.head, 37, 49))
			cmd(RA, 1);
		else
		{
			cmd(PB, 1);
			if (group_n(v, v->b.head, 1, 13))
			{
				if (group_n(v, v->a.head, 37, 49))
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

static void	split_huge_part_11(t_vars *v)
{
	while (!is_group_x(v, v->b.head))
	{
		if (group_n(v, v->b.head, 14, 14))
			cmd(RB, 1);
		else
		{
			cmd(PA, 1);
			if (group_n(v, v->a.head, 1, 1) || \
				group_n(v, v->a.head, 36, 36) || \
				group_n(v, v->a.head, 49, 49))
			{
				if (group_n(v, v->b.head, 14, 14))
					cmd(RR, 1);
				else
					cmd(RA, 1);
			}
		}
	}
}

static void	split_huge_part_10(t_vars *v)
{
	while (!is_group_b(v, v->a.head))
	{
		if (group_n(v, v->a.head, 2, 2) || \
			group_n(v, v->a.head, 35, 35) || \
			group_n(v, v->a.head, 48, 48))
			cmd(RA, 1);
		else
		{
			cmd(PB, 1);
			if (group_n(v, v->b.head, 15, 15))
			{
				if (group_n(v, v->a.head, 2, 2) || \
					group_n(v, v->a.head, 35, 35) || \
					group_n(v, v->a.head, 48, 48))
					cmd(RR, 1);
				else
					cmd(RB, 1);
			}
		}
	}
}

static void	split_huge_part_9(t_vars *v)
{
	while (!is_group_x(v, v->b.head))
	{
		if (group_n(v, v->b.head, 16, 16))
			cmd(RB, 1);
		else
		{
			cmd(PA, 1);
			if (group_n(v, v->a.head, 3, 3) || \
				group_n(v, v->a.head, 34, 34) || \
				group_n(v, v->a.head, 47, 47))
			{
				if (group_n(v, v->b.head, 16, 16))
					cmd(RR, 1);
				else
					cmd(RA, 1);
			}
		}
	}
}

static void	split_huge_part_8(t_vars *v)
{
	while (!is_group_c(v, v->b.head))
	{
		if (group_n(v, v->b.head, 17, 17))
			cmd(RB, 1);
		else
		{
			cmd(PA, 1);
			if (group_n(v, v->a.head, 4, 4) || \
				group_n(v, v->a.head, 33, 33) || \
				group_n(v, v->a.head, 46, 46))
			{
				if (group_n(v, v->b.head, 17, 17))
					cmd(RR, 1);
				else
					cmd(RA, 1);
			}
		}
	}
}

static void	split_huge_part_7(t_vars *v)
{
	while (!is_group_a(v, v->a.head))
	{
		if (group_n(v, v->a.head, 5, 5) || \
			group_n(v, v->a.head, 32, 32) || \
			group_n(v, v->a.head, 45, 45))
			cmd(RA, 1);
		else
		{
			cmd(PB, 1);
			if (group_n(v, v->b.head, 18, 18))
			{
				if (group_n(v, v->a.head, 5, 5) || \
					group_n(v, v->a.head, 32, 32) || \
					group_n(v, v->a.head, 45, 45))
					cmd(RR, 1);
				else
					cmd(RB, 1);
			}
		}
	}
}

static void	split_huge_part_6(t_vars *v)
{
	while (!is_group_c(v, v->b.head))
	{
		if (group_n(v, v->b.head, 19, 19))
			cmd(RB, 1);
		else
		{
			cmd(PA, 1);
			if (group_n(v, v->a.head, 6, 6) || \
				group_n(v, v->a.head, 31, 31) || \
				group_n(v, v->a.head, 44, 44))
			{
				if (group_n(v, v->b.head, 19, 19))
					cmd(RR, 1);
				else
					cmd(RA, 1);
			}
		}
	}
}

static void	split_huge_part_5(t_vars *v)
{
	while (!is_group_b(v, v->b.head))
	{
		if (group_n(v, v->b.head, 20, 20))
			cmd(RB, 1);
		else
		{
			cmd(PA, 1);
			if (group_n(v, v->a.head, 7, 7) || \
				group_n(v, v->a.head, 30, 30) || \
				group_n(v, v->a.head, 43, 43))
			{
				if (group_n(v, v->b.head, 20, 20))
					cmd(RR, 1);
				else
					cmd(RA, 1);
			}
		}
	}
}

static void	split_huge_part_4(t_vars *v)
{
	while (!is_group_x(v, v->a.head))
	{
		if (group_n(v, v->a.head, 8, 8) || \
			group_n(v, v->a.head, 29, 29) || \
			group_n(v, v->a.head, 42, 42))
			cmd(RA, 1);
		else
		{
			cmd(PB, 1);
			if (group_n(v, v->b.head, 21, 21))
			{
				if (group_n(v, v->a.head, 8, 8) || \
					group_n(v, v->a.head, 29, 29) || \
					group_n(v, v->a.head, 42, 42))
					cmd(RR, 1);
				else
					cmd(RB, 1);
			}
		}
	}
}

static void	split_huge_part_3(t_vars *v)
{
	while (!is_group_b(v, v->b.head))
	{
		if (group_n(v, v->b.head, 22, 22))
			cmd(RB, 1);
		else
		{
			cmd(PA, 1);
			if (group_n(v, v->a.head, 9, 9) || \
				group_n(v, v->a.head, 28, 28) || \
				group_n(v, v->a.head, 41, 41))
			{
				if (group_n(v, v->b.head, 22, 22))
					cmd(RR, 1);
				else
					cmd(RA, 1);
			}
		}
	}
}

static void	split_huge_part_x(t_vars *v)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->a.size;
	while (i < size)
	{
		if (is_group_x(v, v->a.head) && !group_n(v, v->a.head, 23, 23))
			cmd(RA, 1);
		else
		{
			cmd(PB, 1);
			if (group_n(v, v->b.head, 23, 23))
			{
				if (is_group_x(v, v->a.head) && !group_n(v, v->a.head, 23, 23))
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

static void	split_huge_part_xabc(t_vars *v)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->a.size;
	while (i < size)
	{
		if (is_group_a(v, v->a.head) || is_group_x(v, v->a.head))
			cmd(RA, 1);
		else
		{
			cmd(PB, 1);
			if (is_group_c(v, v->b.head))
			{
				if (is_group_a(v, v->a.head) || is_group_x(v, v->a.head))
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
