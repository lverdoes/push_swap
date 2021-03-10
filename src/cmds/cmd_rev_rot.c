/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_rev_rot.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 16:06:46 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/10 13:47:23 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "unistd.h"

int	cmd_rra(t_vars *v)
{
	ft_putendl_fd("rra", STDOUT_FILENO);
	rra(v);
	return (1);
}

int	cmd_rrb(t_vars *v)
{
	ft_putendl_fd("rrb", STDOUT_FILENO);
	rrb(v);
	return (1);
}

int	cmd_rrr(t_vars *v)
{
	ft_putendl_fd("rrr", STDOUT_FILENO);
	rrr(v);
	return (1);
}
