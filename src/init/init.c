/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 20:19:12 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/04 09:50:05 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instructions.h"
#include "libft.h"
#include <stdlib.h>

static void	init_functions(t_vars *v)
{
	v->cmd[PA] = cmd_pa;
	v->cmd[PB] = cmd_pb;
	v->cmd[SA] = cmd_sa;
	v->cmd[SB] = cmd_sb;
	v->cmd[SS] = cmd_ss;
	v->cmd[RA] = cmd_ra;
	v->cmd[RB] = cmd_rb;
	v->cmd[RR] = cmd_rr;
	v->cmd[RRA] = cmd_rra;
	v->cmd[RRB] = cmd_rrb;
	v->cmd[RRR] = cmd_rrr;
	void **ptr = cmd(0, 0);
	*ptr = v;
}

static void	free_sorted(t_list *list)
{
	t_list	*tmp;
	t_elem	*e;

	tmp = list;
	while (tmp)
	{
		list = tmp;
		tmp = tmp->next;
		e = list->content;
		free(e);
		free(list);
	}
}

static size_t	list_index(t_list *start, void *data_ref, int (*cmp)())
{
	size_t	ret;
	t_list	*tmp;

	ret = 0;
	tmp = start;
	while (tmp)
	{
		if (!cmp(data_ref, tmp->content))
			break ;
		tmp = tmp->next;
		ret++;
	}
	return (ret);
}

static void	assign_rank(t_vars *v)
{
	t_list	*list;
	t_elem	*elem;

	list = v->a.head;
	while (list)
	{
		elem = list->content;
		elem->rank = list_index(v->sorted, list->content, intcmp);
		list = list->next;
	}
}

void	init(t_vars *v, size_t size, char **args)
{
	t_list	*new;
	t_elem	*element;

	while (size > 0)
	{
		size--;
		check_minmax_int(args[size]);
		check_digits(args[size]);
		element = ft_calloc(1, sizeof(t_elem));
		check_malloc(element);
		new = ft_list_new(element);
		check_malloc(new);
		element->num = ft_atoi(args[size]);
		check_duplicate(v, element->num);
		ft_list_add_front(&v->a.head, new);
	}
	assign_rank(v);
	free_sorted(v->sorted);
	v->total_size = ft_list_size(v->a.head);
	v->a.size = v->total_size;
	v->max_rank = v->total_size - 1;
	v->a.tail = ft_list_last(v->a.head);
	v->a.high = v->max_rank;
	v->a.pos_high = ft_list_index(v->a.head, &v->a.high, rankcmp);
	v->a.pos_low = ft_list_index(v->a.head, &v->a.low, rankcmp);
	init_functions(v);
	v->a.id = STACK_A;
	v->b.id = STACK_B;
}
