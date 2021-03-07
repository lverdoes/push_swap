/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_push_swap.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 16:04:50 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/05 17:59:29 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	cmd_sa(t_vars *v)
{
	ft_putendl_fd("sa", 1);
	sa(v);
	return (1);
}

int	cmd_sb(t_vars *v)
{
	ft_putendl_fd("sb", 1);
	sb(v);
	return (1);
}

int	cmd_ss(t_vars *v)
{
	ft_putendl_fd("ss", 1);
	ss(v);
	return (1);
}

int	cmd_pa(t_vars *v)
{
	ft_putendl_fd("pa", 1);
	pa(v);
	return (1);
}

int	cmd_pb(t_vars *v)
{
	ft_putendl_fd("pb", 1);
	pb(v);
	return (1);
}
