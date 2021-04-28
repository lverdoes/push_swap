/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_push_swap.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 16:04:50 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/27 18:14:18 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "unistd.h"
#include "libft.h"

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
