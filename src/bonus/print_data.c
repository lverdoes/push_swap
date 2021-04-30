/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_data.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 15:55:55 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/30 15:56:22 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_data(t_vars *v)
{
	int total_push;
	int total_rots;
	int total_swap;
	int total;

	total_push =
	v->data.pa +
	v->data.pb;

	total_rots =
	v->data.ra +
	v->data.rb +
	v->data.rr +
	v->data.rra +
	v->data.rrb +
	v->data.rrr;

	total_swap =
	v->data.sa +
	v->data.sb +
	v->data.ss;

	total = 
	total_push +
	total_rots +
	total_swap;


	dprintf(2, "\ntotal instructions = [%d]\n\n", total);
	dprintf(2, "%-4s = [%d]\t[%6.2f%%]\n", "pa", v->data.pa, (float)v->data.pa / total * 100);
	dprintf(2, "%-4s = [%d]\t[%6.2f%%]\n", "pb", v->data.pb, (float)v->data.pb / total * 100);
	dprintf(2, "%-4s = [%d]\t[%6.2f%%]\n", "ra", v->data.ra, (float)v->data.ra / total * 100);
	dprintf(2, "%-4s = [%d]\t[%6.2f%%]\n", "rb", v->data.rb, (float)v->data.rb / total * 100);
	dprintf(2, "%-4s = [%d]\t[%6.2f%%]\n", "rr", v->data.rr, (float)v->data.rr / total * 100);
	dprintf(2, "%-4s = [%d]\t[%6.2f%%]\n", "rra", v->data.rra, (float)v->data.rra / total * 100);
	dprintf(2, "%-4s = [%d]\t[%6.2f%%]\n", "rrb", v->data.rrb, (float)v->data.rrb / total * 100);
	dprintf(2, "%-4s = [%d]\t[%6.2f%%]\n", "rrr", v->data.rrr, (float)v->data.rrr / total * 100);
	dprintf(2, "%-4s = [%d]\t[%6.2f%%]\n", "sa", v->data.sa, (float)v->data.sa / total * 100);
	dprintf(2, "%-4s = [%d]\t[%6.2f%%]\n", "sb", v->data.sb, (float)v->data.sb / total * 100);
	dprintf(2, "%-4s = [%d]\t[%6.2f%%]\n", "ss", v->data.ss, (float)v->data.ss / total * 100);
	dprintf(2, "\n");
	dprintf(2, "%-4s = [%d]\t[%6.2f%%]\n", "push", total_push, (float)total_push / total * 100);
	dprintf(2, "%-4s = [%d]\t[%6.2f%%]\n", "rots", total_rots, (float)total_rots / total * 100);
	dprintf(2, "%-4s = [%d]\t[%6.2f%%]\n", "swap", total_swap, (float)total_swap / total * 100);
	dprintf(2, "\n");
}
