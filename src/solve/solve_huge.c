/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_huge.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 20:57:26 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/01 17:40:02 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	split_huge_part_finish(t_vars *v)	//xabc3 from A stack
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->size_a;
	while (i < size)
	{
		if (group_n(v, v->a, 37, 49))
			cmd_ra(v);
		else
		{
			cmd_pb(v);
			if (group_n(v, v->b, 1, 13))
			{
				if (group_n(v, v->a, 37, 49))
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

static void	split_huge_part_11(t_vars *v)	//c7 from B stack
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->size_b;
	while (i < size)
	{
		if (is_group_x(v, v->b))
			return ;
		if (group_n(v, v->b, 14, 14))
			cmd_rb(v);
		else
		{
			cmd_pa(v);
			if (group_n(v, v->a, 1, 1) || group_n(v, v->a, 36, 36) || group_n(v, v->a, 49, 49))
			{
				if (group_n(v, v->b, 14, 14))
				{
					cmd_rr(v);
					i++;
				}
				else
					cmd_ra(v);
			}
		}
		i++;
	}
}

static void	split_huge_part_10(t_vars *v)	//c11 from A stack
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->size_a;
	while (i < size)
	{
		if (is_group_b(v, v->a))
			return ;
		if (group_n(v, v->a, 2, 2) || group_n(v, v->a, 35, 35) || group_n(v, v->a, 48, 48))
			cmd_ra(v);
		else
		{
			cmd_pb(v);
			if (group_n(v, v->b, 15, 15))
			{
				if (group_n(v, v->a, 2, 2) || group_n(v, v->a, 35, 35) || group_n(v, v->a, 48, 48))
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

static void	split_huge_part_9(t_vars *v)	//c15 from B stack
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->size_b;
	while (i < size)
	{
		if (is_group_x(v, v->b))
			return ;
		if (group_n(v, v->b, 16, 16))
			cmd_rb(v);
		else
		{
			cmd_pa(v);
			if (group_n(v, v->a, 3, 3) || group_n(v, v->a, 34, 34) || group_n(v, v->a, 47, 47))
			{
				if (group_n(v, v->b, 16, 16))
				{
					cmd_rr(v);
					i++;
				}
				else
					cmd_ra(v);
			}
		}
		i++;
	}
}

static void	split_huge_part_8(t_vars *v)	//b7 from B stack
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->size_b;
	while (i < size)
	{
		if (is_group_c(v, v->b))
			return ;
		if (group_n(v, v->b, 17, 17))
			cmd_rb(v);
		else
		{
			cmd_pa(v);
			if (group_n(v, v->a, 4, 4) || group_n(v, v->a, 33, 33) || group_n(v, v->a, 46, 46))
			{
				if (group_n(v, v->b, 17, 17))
				{
					cmd_rr(v);
					i++;
				}
				else
					cmd_ra(v);
			}
		}
		i++;
	}
}

static void	split_huge_part_7(t_vars *v)	//b11 from A stack
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->size_a;
	while (i < size)
	{
		if (is_group_a(v, v->a))
			return ;
		if (group_n(v, v->a, 5, 5) || group_n(v, v->a, 32, 32) || group_n(v, v->a, 45, 45))
			cmd_ra(v);
		else
		{
			cmd_pb(v);
			if (group_n(v, v->b, 18, 18))
			{
				if (group_n(v, v->a, 5, 5) || group_n(v, v->a, 32, 32) || group_n(v, v->a, 45, 45))
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

static void	split_huge_part_6(t_vars *v)	//b15 from B stack
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->size_b;
	while (i < size)
	{
		if (is_group_c(v, v->b))
			return ;
		if (group_n(v, v->b, 19, 19))
			cmd_rb(v);
		else
		{
			cmd_pa(v);
			if (group_n(v, v->a, 6, 6) || group_n(v, v->a, 31, 31) || group_n(v, v->a, 44, 44))
			{
				if (group_n(v, v->b, 19, 19))
				{
					cmd_rr(v);
					i++;
				}
				else
					cmd_ra(v);
			}
		}
		i++;
	}
}

static void	split_huge_part_5(t_vars *v)	//a7 from B stack
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->size_b;
	while (i < size)
	{
		if (is_group_b(v, v->b))
			return ;
		if (group_n(v, v->b, 20, 20))
			cmd_rb(v);
		else
		{
			cmd_pa(v);
			if (group_n(v, v->a, 7, 7) || group_n(v, v->a, 30, 30) || group_n(v, v->a, 43, 43))
			{
				if (group_n(v, v->b, 20, 20))
				{
					cmd_rr(v);
					i++;
				}
				else
					cmd_ra(v);
			}
		}
		i++;
	}
}

static void	split_huge_part_4(t_vars *v)	//a11 from A stack
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->size_a;
	while (i < size)
	{
		if (is_group_x(v, v->a))
			return ;
		if (group_n(v, v->a, 8, 8) || group_n(v, v->a, 29, 29) || group_n(v, v->a, 42, 42))
			cmd_ra(v);
		else
		{
			cmd_pb(v);
			if (group_n(v, v->b, 21, 21))
			{
				if (group_n(v, v->a, 8, 8) || group_n(v, v->a, 29, 29) || group_n(v, v->a, 42, 42))
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

static void	split_huge_part_3(t_vars *v)	//a15 from b stack
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->size_b;
	while (i < size)
	{
		if (is_group_b(v, v->b))
			return ;
		if (group_n(v, v->b, 22, 22))
			cmd_rb(v);
		else
		{
			cmd_pa(v);
			if (group_n(v, v->a, 9, 9) || group_n(v, v->a, 28, 28) || group_n(v, v->a, 41, 41))
			{
				if (group_n(v, v->b, 22, 22))
				{
					cmd_rr(v);
					i++;
				}
				else
					cmd_ra(v);
			}
		}
		i++;
	}
}

static void	split_huge_part_x(t_vars *v)	//x4 from A stack
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->size_a;
	while (i < size)
	{
		if (is_group_x(v, v->a) && !group_n(v, v->a, 23, 23))
			cmd_ra(v);
		else
		{
			cmd_pb(v);
			if (group_n(v, v->b, 23, 23))
			{
				if (is_group_x(v, v->a) && !group_n(v, v->a, 23, 23))
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

static void	split_huge_part_xabc(t_vars *v)	//xabc49 from A stack
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->size_a;
	while (i < size)
	{
		if (is_group_a(v, v->a) || is_group_x(v, v->a))
			cmd_ra(v);
		else
		{
			cmd_pb(v);
			if (is_group_c(v, v->b))
			{
				if (is_group_a(v, v->a) || is_group_x(v, v->a))
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
