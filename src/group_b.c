/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   group_b.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/07 20:51:48 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/09 08:03:08 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	group_b1(t_vars *v, t_node *stack)
{
	if (group_large(v, stack, 12))
		return (1);
	return (0);
}

int	group_b2(t_vars *v, t_node *stack)
{
	if (group_large(v, stack, 15))
		return (1);
	return (0);
}

int	group_b3(t_vars *v, t_node *stack)
{
	if (group_small(v, stack, 5))
		return (1);
	if (group_small(v, stack, 4))
		return (1);
	if (group_small(v, stack, 1))
		return (1);
	return (0);
}
