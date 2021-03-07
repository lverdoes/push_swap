/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_rot.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 16:07:39 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/05 17:59:36 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	cmd_ra(t_vars *v)
{
	ft_putendl_fd("ra", 1);
	ra(v);
	return (1);
}

int	cmd_rb(t_vars *v)
{
	ft_putendl_fd("rb", 1);
	rb(v);
	return (1);
}

int	cmd_rr(t_vars *v)
{
	ft_putendl_fd("rr", 1);
	rr(v);
	return (1);
}
