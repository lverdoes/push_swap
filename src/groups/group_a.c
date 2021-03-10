/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   group_a.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/09 10:27:39 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/09 10:32:13 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	group_a2(t_vars *v, t_node *stack)
{
	if (group_small(v, stack, 19))
		return (1);
	return (0);
}

int	group_a3(t_vars *v, t_node *stack)
{
	if (group_small(v, stack, 20))
		return (1);
	return (0);
}
