/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_rev_rot.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 16:06:46 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/05 17:59:33 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	cmd_rra(t_vars *v)
{
	ft_putendl_fd("rra", 1);
	rra(v);
	return (1);
}

int	cmd_rrb(t_vars *v)
{
	ft_putendl_fd("rrb", 1);
	rrb(v);
	return (1);
}

int	cmd_rrr(t_vars *v)
{
	ft_putendl_fd("rrr", 1);
	rrr(v);
	return (1);
}
