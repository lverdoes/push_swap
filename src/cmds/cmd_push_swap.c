/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_push_swap.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 16:04:50 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/28 18:06:51 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "unistd.h"

// PINK = \x1b[35;01m
// BLUE = \x1b[34;01m
// YELLOW = \x1b[33;01m
// GREEN = \x1b[32;01m
// RED = \x1b[31;01m
// WHITE = \x1b[31;37m
// RESET = \x1b[0m

int	cmd_sa(t_vars *v)
{
	ft_putendl_fd("sa", STDOUT_FILENO);
	sa(v);
	return (1);
}

int	cmd_sb(t_vars *v)
{
	ft_putendl_fd("sb", STDOUT_FILENO);
	sb(v);
	return (1);
}

int	cmd_ss(t_vars *v)
{
	ft_putendl_fd("ss", STDOUT_FILENO);
	ss(v);
	return (1);
}

int	cmd_pa(t_vars *v)
{
	ft_putendl_fd("pa", STDOUT_FILENO);
	pa(v);
	return (1);
}

int	cmd_pb(t_vars *v)
{
	ft_putendl_fd("pb", STDOUT_FILENO);
	pb(v);
	return (1);
}
