/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_huge.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 20:57:26 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/01 13:34:03 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

	// a		1	6	7	8	13	14	17	18	19	24	25	26	31
	// b				2	5	9	12	16	20	23	27	30
	// c				3	4	10	11	15	21	22	28	29

static void	split_huge_part_7(t_vars *v)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->size_a;
	while (i < size)
	{
		if (group_n(v, v->a, 25, 31))
			cmd_ra(v);
		else
		{
			cmd_pb(v);
			if (group_n(v, v->b, 1, 7))
			{
				if (group_n(v, v->a, 25, 31))
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

static void	split_huge_part_6(t_vars *v)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->size_a;
	while (i < size)
	{
		if (group_n(v, v->a, 7, 7) || group_n(v, v->a, 18, 18) || group_n(v, v->a, 25, 25))
			return ;
		if (group_n(v, v->a, 1, 3) || group_n(v, v->a, 22, 24) || group_n(v, v->a, 29, 31))
			cmd_ra(v);
		else
		{
			cmd_pb(v);
			if (group_n(v, v->b, 8, 10))
			{
				if (group_n(v, v->a, 1, 3) || group_n(v, v->a, 22, 24) || group_n(v, v->a, 29, 31))
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

static void	split_huge_part_5(t_vars *v)	//c from b stack
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->size_b;
	while (i < size)
	{
		if (group_n(v, v->b, 14, 14))
			return ;
		if (group_n(v, v->b, 11, 11))
			cmd_rb(v);
		else
		{
			cmd_pa(v);
			if (group_n(v, v->a, 4, 4) || group_n(v, v->a, 21, 21) || group_n(v, v->a, 28, 28))
			{
				if (group_n(v, v->b, 11, 11))
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

static void	split_huge_part_4(t_vars *v)	// b from b stack
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->size_b;
	while (i < size)
	{
		if (is_group_c(v, v->b))
			return ;
		if (group_n(v, v->b, 12, 12))
			cmd_rb(v);
		else
		{
			cmd_pa(v);
			if (group_n(v, v->a, 5, 5) || group_n(v, v->a, 20, 20) || group_n(v, v->a, 27, 27))
			{
				if (group_n(v, v->b, 12, 12))
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

static void	split_huge_part_3(t_vars *v)	//a from b stack
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->size_b;
	while (i < size)
	{
		if (is_group_b(v, v->b))
			return ;
		if (group_n(v, v->b, 13, 13))
			cmd_rb(v);
		else
		{
			cmd_pa(v);
			if (group_n(v, v->a, 6, 6) || group_n(v, v->a, 19, 19) || group_n(v, v->a, 26, 26))
			{
				if (group_n(v, v->b, 13, 13))
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

static void	split_huge_part_2(t_vars *v)	//a from a stack
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->size_a;
	while (i < size)
	{
		if (group_n(v, v->a, 7, 7) || group_n(v, v->a, 18, 18) || group_n(v, v->a, 25, 25))
			cmd_ra(v);
		else
		{
			cmd_pb(v);
			if (group_n(v, v->b, 14, 14))
			{
				if (group_n(v, v->a, 7, 7) || group_n(v, v->a, 18, 18) || group_n(v, v->a, 25, 25))
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

static void	split_huge_part_abc(t_vars *v)	//abc from a stack
{
	size_t	i;
	size_t	size;

	i = 0;
	size = v->size_a;
	while (i < size)
	{
		if (is_group_a(v, v->a))
			cmd_ra(v);
		else
		{
			cmd_pb(v);
			if (is_group_c(v, v->b))
			{
				if (is_group_a(v, v->a))
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
	split_huge_part_abc(v);
	split_huge_part_2(v);
	split_huge_part_3(v);
	split_huge_part_4(v);
	split_huge_part_5(v);
	split_huge_part_6(v);
	split_huge_part_7(v);
	solve_medium(v, 2);
	return (1);
}
