/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   group_b.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 20:51:48 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/16 17:30:55 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	group_b1(t_vars *v, t_node *stack)
{
	if (group_large(v, stack, 7))
		return (1);
	return (0);
}

int	group_b2(t_vars *v, t_node *stack)
{
	if (group_large(v, stack, 13))
		return (1);
	return (0);
}

int	group_b3(t_vars *v, t_node *stack)
{
	if (group_b3a(v, stack))
		return (1);
	if (group_b3b(v, stack))
		return (1);
	if (group_b3c(v, stack))
		return (1);
	return (0);
}

int	group_b3a(t_vars *v, t_node *stack)
{
	if (group_small(v, stack, 19))
		return (1);
	return (0);
}

int	group_b3b(t_vars *v, t_node *stack)
{
	if (group_small(v, stack, 3))
		return (1);
	return (0);
}

int	group_b3c(t_vars *v, t_node *stack)
{
	if (group_small(v, stack, 1))
		return (1);
	return (0);
}
