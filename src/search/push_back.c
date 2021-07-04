/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_back.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/04 09:29:59 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/04 10:48:44 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_back(t_vars *v)
{
	while (v->b.head)
	{
		if (swap_routine(v))
			continue ;
		shortest_path(&v->b, v->b.pos_high, 1);
		if (v->b.pos_high == 0)
			cmd(PA, 1);
	}
	return (1);
}
