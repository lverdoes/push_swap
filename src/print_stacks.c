/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_stacks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/28 14:28:25 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/28 17:50:04 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>
#include <unistd.h>

void	print_line(t_node *n_a, t_node *n_b)
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
	usleep(80000);
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
//	printf("\E[H\E[2J");
}
