/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_data.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 15:55:55 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/03 15:53:41 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	calc_totals(t_vars *v)
{
	v->data.total_push = \
	v->data.count[PA] + v->data.count[PB];
	v->data.total_rots = \
	v->data.count[RA] + v->data.count[RB] + v->data.count[RR] + \
	v->data.count[RRA] + v->data.count[RRB] + v->data.count[RRR];
	v->data.total_swap = \
	v->data.count[SA] + v->data.count[SB] + v->data.count[SS];
	v->data.total = \
	v->data.total_push + v->data.total_rots + v->data.total_swap;
}

static void	print_subtotals(t_vars *v)
{
	dprintf(2, "%-4s = [%d]\t[%6.2f%%]\n", "pa", \
	v->data.count[PA], (float)v->data.count[PA] / v->data.total * 100);
	dprintf(2, "%-4s = [%d]\t[%6.2f%%]\n", "pb", \
	v->data.count[PB], (float)v->data.count[PB] / v->data.total * 100);
	dprintf(2, "%-4s = [%d]\t[%6.2f%%]\n", "ra", \
	v->data.count[RA], (float)v->data.count[RA] / v->data.total * 100);
	dprintf(2, "%-4s = [%d]\t[%6.2f%%]\n", "rb", \
	v->data.count[RB], (float)v->data.count[RB] / v->data.total * 100);
	dprintf(2, "%-4s = [%d]\t[%6.2f%%]\n", "rr", \
	v->data.count[RR], (float)v->data.count[RR] / v->data.total * 100);
	dprintf(2, "%-4s = [%d]\t[%6.2f%%]\n", "rra", \
	v->data.count[RRA], (float)v->data.count[RRA] / v->data.total * 100);
	dprintf(2, "%-4s = [%d]\t[%6.2f%%]\n", "rrb", \
	v->data.count[RRB], (float)v->data.count[RRB] / v->data.total * 100);
	dprintf(2, "%-4s = [%d]\t[%6.2f%%]\n", "rrr", \
	v->data.count[RRR], (float)v->data.count[RRR] / v->data.total * 100);
	dprintf(2, "%-4s = [%d]\t[%6.2f%%]\n", "sa", \
	v->data.count[SA], (float)v->data.count[SA] / v->data.total * 100);
	dprintf(2, "%-4s = [%d]\t[%6.2f%%]\n", "sb", \
	v->data.count[SB], (float)v->data.count[SB] / v->data.total * 100);
	dprintf(2, "%-4s = [%d]\t[%6.2f%%]\n", "ss", \
	v->data.count[SS], (float)v->data.count[SS] / v->data.total * 100);
}

static void	print_totals(t_vars *v)
{
	dprintf(2, "%-4s = [%d]\t[%6.2f%%]\n", "push", \
	v->data.total_push, (float)v->data.total_push / v->data.total * 100);
	dprintf(2, "%-4s = [%d]\t[%6.2f%%]\n", "rots", \
	v->data.total_rots, (float)v->data.total_rots / v->data.total * 100);
	dprintf(2, "%-4s = [%d]\t[%6.2f%%]\n", "swap", \
	v->data.total_swap, (float)v->data.total_swap / v->data.total * 100);
}

void	print_data(t_vars *v)
{
	calc_totals(v);
	dprintf(2, "\ntotal instructions = [%d]\n\n", v->data.total);
	print_subtotals(v);
	dprintf(2, "\n");
	print_totals(v);
	dprintf(2, "\n");
}
