/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_back.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/04 09:29:59 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/14 13:59:55 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap_check_stack_a(t_stack *a)
{
	size_t	rank[2];

	if (a->size < 2)
		return (0);
	rank[0] = ((t_elem *)a->head->content)->rank;
	rank[1] = ((t_elem *)a->head->next->content)->rank;
	if (a->pos_low == 1 && rank[0] == a->low + 1)
		return (1);
	return (0);
}

static int	swap_check_stack_b(t_stack *b)
{
	size_t	rank[4];

	if (b->size < 2)
		return (0);
	rank[0] = ((t_elem *)b->head->content)->rank;
	rank[1] = ((t_elem *)b->head->next->content)->rank;
	if (b->pos_high == 1 && rank[0] + 1 == b->high)
	{
		if (b->size > 3)
		{
			rank[2] = ((t_elem *)b->head->next->next->content)->rank;
			rank[3] = ((t_elem *)b->head->next->next->next->content)->rank;
			if (rank[2] + 3 == b->high && rank[3] + 2 == b->high)
				return (2);
		}
		return (1);
	}
	return (0);
}

static void	swap_check(t_stack *a, t_stack *b)
{
	if (swap_check_stack_b(b) == 1)
	{
		if (swap_check_stack_a(a))
			cmd(SS, 1);
		cmd(PA, 2);
	}
	else if (swap_check_stack_b(b) == 2)
	{
		if (swap_check_stack_a(a))
		{
			cmd(SS, 1);
			cmd(PA, 4);
		}
		else
		{
			cmd(PA, 2);
			cmd(SS, 1);
			cmd(PA, 2);
		}
	}
	else
	{
		if (swap_check_stack_a(a))
			cmd(SS, 1);
		else
			cmd(SB, 1);
	}
}

int	push_back(t_stack *a, t_stack *b)
{
	while (b->head)
	{
		if (b->pos_high == 1)
			swap_check(a, b);
		if (b->pos_high == 0)
		{
			if (swap_check_stack_a(a))
				cmd(SA, 1);
			if (b->size)
				cmd(PA, 1);
		}
		else
			shortest_path(b, b->pos_high, 1);
	}
	if (swap_check_stack_a(a))
		cmd(SA, 1);
	return (0);
}
