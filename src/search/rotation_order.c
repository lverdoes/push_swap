/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotation_order.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/04 19:26:47 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/04 08:42:58 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_correct_rotation_order(t_stack *s)
{
	t_list	*tmp[2];
	t_elem	*elem[2];
	int		exception;

	tmp[0] = s->head;
	tmp[1] = tmp[0]->next;
	exception = 0;
	while (tmp[0])
	{
		if (!tmp[0]->next)
			tmp[1] = s->head;
		elem[0] = tmp[0]->content;
		elem[1] = tmp[1]->content;
		if (elem[0]->rank > elem[1]->rank)
		{
			if (exception == 1)
				return (0);
			exception = 1;
		}
		tmp[0] = tmp[0]->next;
		if (tmp[0])
			tmp[1] = tmp[0]->next;
	}
	return (1);
}
