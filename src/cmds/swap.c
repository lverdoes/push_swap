/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 16:39:50 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/04 21:56:00 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_vars *v)
{
	if (!v->a || !v->a->next)
		return ;
	swap(v->a->content, v->a->next->content);
}

void	sb(t_vars *v)
{
	if (!v->b || !v->b->next)
		return ;
	swap(v->b->content, v->b->next->content);
}

void	ss(t_vars *v)
{
	sa(v);
	sb(v);
}
