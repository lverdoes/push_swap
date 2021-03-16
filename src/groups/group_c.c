/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   group_c.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 20:52:24 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/16 17:12:57 by lverdoes      ########   odam.nl         */
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

int	group_c3a(t_vars *v, t_node *stack)
{
	if (group_small(v, stack, 3))
		return (1);
	return (0);
}

int	group_c3b(t_vars *v, t_node *stack)
{
	if (group_small(v, stack, 2))
		return (1);
	return (0);
}

int	group_c3c(t_vars *v, t_node *stack)
{
	if (group_small(v, stack, 0))
		return (1);
	return (0);
}

int	group_c3(t_vars *v, t_node *stack)
{
	if (group_c3a(v, stack))
		return (1);
	if (group_c3b(v, stack))
		return (1);
	if (group_c3c(v, stack))
		return (1);
	return (0);
}
