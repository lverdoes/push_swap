/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 16:40:27 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/10 10:53:36 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	pa(t_vars *v)
{
	t_node	*tmp;

	if (!v->b)
		return (0);
	tmp = v->b;
	ft_node_unlink(&v->b, v->b);
	ft_node_add_front(&v->a, tmp);
	v->size_b -= 1;
	v->size_a += 1;
	if (!v->b)
		v->last_b = NULL;
	if (!v->a->next)
		v->last_a = v->a;
	return (1);
}

int	pb(t_vars *v)
{
	t_node	*tmp;

	if (!v->a)
		return (0);
	tmp = v->a;
	ft_node_unlink(&v->a, v->a);
	ft_node_add_front(&v->b, tmp);
	v->size_a -= 1;
	v->size_b += 1;
	if (!v->a)
		v->last_a = NULL;
	if (!v->b->next)
		v->last_b = v->b;
	return (1);
}
