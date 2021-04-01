/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_stacks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/28 14:28:25 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/01 18:32:02 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <unistd.h>
#include <stdio.h>

static void	print_line(t_node *n_a, t_node *n_b)
{
	t_elem	*a;
	t_elem	*b;

	if (n_a)
	{
		a = n_a->content;
		printf("\t[%11d]", a->num);
	}
	else
		printf("\t[           ]");
	if (n_b)
	{
		b = n_b->content;
		printf("\t[%11d]", b->num);
	}
	else
		printf("\t[           ]");
}

void	print_stacks(t_vars *v, char *next_cmd)
{
	t_node	*n_a;
	t_node	*n_b;

	n_a = v->a;
	n_b = v->b;
	usleep(800000);
	printf("\E[H\E[2J");
	printf("           stack A         stack B\n");
	printf("cmd:[%s]\n", next_cmd);
	while (n_a || n_b)
	{
		print_line(n_a, n_b);
		if (n_a)
			n_a = n_a->next;
		if (n_b)
			n_b = n_b->next;
		printf("\n");
	}
	printf("\n");
}

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


	printf("total=[%d]\n\n", total);
	printf("pa  = [%d]\t[%5.2f%%]\n", v->data.pa, (float)v->data.pa / total * 100);
	printf("pb  = [%d]\t[%5.2f%%]\n", v->data.pb, (float)v->data.pb / total * 100);
	printf("ra  = [%d]\t[%5.2f%%]\n", v->data.ra, (float)v->data.ra / total * 100);
	printf("rb  = [%d]\t[%5.2f%%]\n", v->data.rb, (float)v->data.rb / total * 100);
	printf("rr  = [%d]\t[%5.2f%%]\n", v->data.rr, (float)v->data.rr / total * 100);
	printf("rra = [%d]\t[%5.2f%%]\n", v->data.rra, (float)v->data.rra / total * 100);
	printf("rrb = [%d]\t[%5.2f%%]\n", v->data.rrb, (float)v->data.rrb / total * 100);
	printf("rrr = [%d]\t[%5.2f%%]\n", v->data.rrr, (float)v->data.rrr / total * 100);
	printf("sa  = [%d]\t[%5.2f%%]\n", v->data.sa, (float)v->data.sa / total * 100);
	printf("sb  = [%d]\t[%5.2f%%]\n", v->data.sb, (float)v->data.sb / total * 100);
	printf("ss  = [%d]\t[%5.2f%%]\n", v->data.ss, (float)v->data.ss / total * 100);
	printf("\n");
	printf("push  = [%d]\t[%5.2f%%]\n", total_push, (float)total_push / total * 100);
	printf("rots  = [%d]\t[%5.2f%%]\n", total_rots, (float)total_rots / total * 100);
	printf("swap  = [%d]\t[%5.2f%%]\n", total_swap, (float)total_swap / total * 100);
}
