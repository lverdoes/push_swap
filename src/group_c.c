/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   group_c.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 20:52:24 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/07 20:54:00 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	group_c1(t_vars *v, t_node *stack)
{
	if (group_large(v, stack, 6))
		return (1);
	return (0);
}

int	group_c2(t_vars *v, t_node *stack)
{
	if (group_large(v, stack, 9))
		return (1);
	return (0);
}

int	group_c3(t_vars *v, t_node *stack)
{
	if (group_small(v, stack, 3))
		return (1);
	if (group_small(v, stack, 2))
		return (1);
	if (group_small(v, stack, 0))
		return (1);
	return (0);
}
