/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 16:40:43 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/03 23:30:45 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_pos(size_t *const pos, size_t size)
{
	if (*pos == size - 1)
		*pos = 0;
	else
		*pos += 1;
}

static int	reverse_rotate(t_stack *s)
{
	t_list	*tmp;
	t_list	*tmp_last;

	if (s->size < 2)
		return (1);
	tmp = s->tail;
	tmp_last = s->tail->prev;
	ft_list_unlink(&s->head, tmp);
	ft_list_add_front(&s->head, tmp);
	s->tail = tmp_last;
	update_pos(&s->pos_high, s->size);
	update_pos(&s->pos_low, s->size);
	return (0);
}

int	rra(t_vars *v)
{
	v->data.count[RRA]++;
	reverse_rotate(&v->a);
	return (0);
}

int	rrb(t_vars *v)
{
	v->data.count[RRB]++;
	reverse_rotate(&v->b);
	return (0);
}

int	rrr(t_vars *v)
{
	v->data.count[RRR]++;
	v->data.count[RRA]--;
	v->data.count[RRB]--;
	rra(v);
	rrb(v);
	return (0);
}
