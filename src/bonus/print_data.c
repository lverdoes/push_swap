/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_data.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 15:55:55 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/05/01 00:48:28 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

static void	calc_totals(t_vars *v)
{
	v->data.total_push = v->data.pa + v->data.pb;
	v->data.total_rots = v->data.ra + v->data.rb + v->data.rr + \
	v->data.rra + v->data.rrb + v->data.rrr;
	v->data.total_swap = v->data.sa + v->data.sb + v->data.ss;
	v->data.total = \
	v->data.total_push + v->data.total_rots + v->data.total_swap;
}

static void	print_colorsubtotals(t_vars *v)
{
	printf("%-4s = [%d]\t[%6.2f%%]\n", COLOR_PA, \
	v->data.pa, (float)v->data.pa / v->data.total * 100);
	printf("%-4s = [%d]\t[%6.2f%%]\n", COLOR_PB, \
	v->data.pb, (float)v->data.pb / v->data.total * 100);
	printf("%-4s = [%d]\t[%6.2f%%]\n", COLOR_RA, \
	v->data.ra, (float)v->data.ra / v->data.total * 100);
	printf("%-4s = [%d]\t[%6.2f%%]\n", COLOR_RB, \
	v->data.rb, (float)v->data.rb / v->data.total * 100);
	printf("%-4s = [%d]\t[%6.2f%%]\n", COLOR_RR, \
	v->data.rr, (float)v->data.rr / v->data.total * 100);
	printf("%-4s = [%d]\t[%6.2f%%]\n", COLOR_RRA, \
	v->data.rra, (float)v->data.rra / v->data.total * 100);
	printf("%-4s = [%d]\t[%6.2f%%]\n", COLOR_RRB, \
	v->data.rrb, (float)v->data.rrb / v->data.total * 100);
	printf("%-4s = [%d]\t[%6.2f%%]\n", COLOR_RRR, \
	v->data.rrr, (float)v->data.rrr / v->data.total * 100);
	printf("%-4s = [%d]\t[%6.2f%%]\n", COLOR_SA, \
	v->data.sa, (float)v->data.sa / v->data.total * 100);
	printf("%-4s = [%d]\t[%6.2f%%]\n", COLOR_SB, \
	v->data.sb, (float)v->data.sb / v->data.total * 100);
	printf("%-4s = [%d]\t[%6.2f%%]\n", COLOR_SS, \
	v->data.ss, (float)v->data.ss / v->data.total * 100);
}

static void	print_subtotals(t_vars *v)
{
	printf("%-4s = [%d]\t[%6.2f%%]\n", "pa", \
	v->data.pa, (float)v->data.pa / v->data.total * 100);
	printf("%-4s = [%d]\t[%6.2f%%]\n", "pb", \
	v->data.pb, (float)v->data.pb / v->data.total * 100);
	printf("%-4s = [%d]\t[%6.2f%%]\n", "ra", \
	v->data.ra, (float)v->data.ra / v->data.total * 100);
	printf("%-4s = [%d]\t[%6.2f%%]\n", "rb", \
	v->data.rb, (float)v->data.rb / v->data.total * 100);
	printf("%-4s = [%d]\t[%6.2f%%]\n", "rr", \
	v->data.rr, (float)v->data.rr / v->data.total * 100);
	printf("%-4s = [%d]\t[%6.2f%%]\n", "rra", \
	v->data.rra, (float)v->data.rra / v->data.total * 100);
	printf("%-4s = [%d]\t[%6.2f%%]\n", "rrb", \
	v->data.rrb, (float)v->data.rrb / v->data.total * 100);
	printf("%-4s = [%d]\t[%6.2f%%]\n", "rrr", \
	v->data.rrr, (float)v->data.rrr / v->data.total * 100);
	printf("%-4s = [%d]\t[%6.2f%%]\n", "sa", \
	v->data.sa, (float)v->data.sa / v->data.total * 100);
	printf("%-4s = [%d]\t[%6.2f%%]\n", "sb", \
	v->data.sb, (float)v->data.sb / v->data.total * 100);
	printf("%-4s = [%d]\t[%6.2f%%]\n", "ss", \
	v->data.ss, (float)v->data.ss / v->data.total * 100);
}

static void	print_totals(t_vars *v)
{
	printf("%-4s = [%d]\t[%6.2f%%]\n", "push", \
	v->data.total_push, (float)v->data.total_push / v->data.total * 100);
	printf("%-4s = [%d]\t[%6.2f%%]\n", "rots", \
	v->data.total_rots, (float)v->data.total_rots / v->data.total * 100);
	printf("%-4s = [%d]\t[%6.2f%%]\n", "swap", \
	v->data.total_swap, (float)v->data.total_swap / v->data.total * 100);
}

void	print_data(t_vars *v)
{
	calc_totals(v);
	printf("\ntotal instructions = [%d]\n\n", v->data.total);
	if (v->opt.color)
		print_colorsubtotals(v);
	else
		print_subtotals(v);
	printf("\n");
	print_totals(v);
	printf("\n");
}
