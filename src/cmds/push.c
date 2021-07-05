/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 16:40:27 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/05 00:06:06 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static void	update_pos(t_stack *src, t_stack *dst)
{
	t_elem	*e;

	e = dst->head->content;
	if (dst->size == 1)
	{
		dst->pos_high = 0;
		dst->pos_low = 0;
	}
	else if (e->rank > dst->high)
	{
		dst->high = e->rank;
		dst->pos_high = 0;
		dst->pos_low++;
	}
	else if (e->rank < dst->low)
	{
		dst->low = e->rank;
		dst->pos_low = 0;
		dst->pos_high++;
	}
	else
	{
		dst->pos_high++;
		dst->pos_low++;
	}
	if (src->head)
	{
		if (e->rank == src->high)
		{
			find_highest_rank(src);
			src->pos_low--;
		}
		else if (e->rank == src->low)
		{
			find_lowest_rank(src);
			src->pos_high--;
		}
		else
		{
			src->pos_high--;
			src->pos_low--;
		}
	}
	else
	{
		src->pos_high = 0;
		src->pos_low = 0;
		src->low = INT_MAX;
		src->high = 0;
	}
}

static t_list	*pop(t_stack *src)
{
	t_list	*pop;

	if (src->size == 0)
		return (NULL);
	pop = ft_list_unlink(&src->head, src->head);
	src->size -= 1;
	if (!src->head)
		src->tail = NULL;
	return (pop);
}

static void	push(t_stack *src, t_stack *dst, t_list *tmp)
{
	ft_list_add_front(&dst->head, tmp);
	dst->size += 1;
	if (!dst->head->next)
		dst->tail = dst->head;
	update_pos(src, dst);
}

int	pa(t_vars *v)
{
	t_list	*tmp;

	v->data.count[PA]++;
	tmp = pop(&v->b);
	if (tmp)
		push(&v->b, &v->a, tmp);
	return (0);
}

int	pb(t_vars *v)
{
	t_list	*tmp;

	v->data.count[PB]++;
	tmp = pop(&v->a);
	if (tmp)
		push(&v->a, &v->b, tmp);
	return (0);
}
