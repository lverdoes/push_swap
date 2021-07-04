/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 16:39:50 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/03 23:31:27 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_ext.h"

static void	update_pos(size_t *const pos)
{
	if (*pos == 0)
		*pos = 1;
	else if (*pos == 1)
		*pos = 0;
}

static int	swap(t_stack *s)
{
	if (s->size < 2)
		return (1);
	ft_swap(s->head->content, s->head->next->content, sizeof(void *));
	if (s->size == 2)
		s->tail = ft_list_last(s->head);
	update_pos(&s->pos_high);
	update_pos(&s->pos_low);
	return (0);
}

int	sa(t_vars *v)
{
	v->data.count[SA]++;
	swap(&v->a);
	return (0);
}

int	sb(t_vars *v)
{
	v->data.count[SB]++;
	swap(&v->b);
	return (0);
}

int	ss(t_vars *v)
{
	v->data.count[SS]++;
	v->data.count[SA]--;
	v->data.count[SB]--;
	sa(v);
	sb(v);
	return (0);
}
