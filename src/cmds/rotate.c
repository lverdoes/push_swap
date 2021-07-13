/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 16:40:50 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/13 12:49:44 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_pos(size_t *const pos, size_t size)
{
	if (*pos == 0)
		*pos = size - 1;
	else
		*pos -= 1;
}

static int	rotate(t_stack *s)
{
	t_list	*tmp;

	if (s->size < 2)
		return (1);
	tmp = s->head;
	ft_list_unlink(&s->head, s->head);
	ft_list_insert_after(&s->head, tmp, s->tail);
	s->tail = tmp;
	update_pos(&s->pos_high, s->size);
	update_pos(&s->pos_low, s->size);
	return (0);
}

int	ra(t_vars *v)
{
	v->data.count[RA]++;
	rotate(&v->a);
	return (0);
}

int	rb(t_vars *v)
{
	v->data.count[RB]++;
	rotate(&v->b);
	return (0);
}

int	rr(t_vars *v)
{
	v->data.count[RR]++;
	v->data.count[RA]--;
	v->data.count[RB]--;
	ra(v);
	rb(v);
	return (0);
}
