/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_rot.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 16:07:39 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/27 18:14:06 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "unistd.h"
#include "libft.h"

int	cmd_ra(t_vars *v)
{
	ft_putendl_fd("ra", STDOUT_FILENO);
	ra(v);
	return (1);
}

int	cmd_rb(t_vars *v)
{
	ft_putendl_fd("rb", STDOUT_FILENO);
	rb(v);
	return (1);
}

int	cmd_rr(t_vars *v)
{
	ft_putendl_fd("rr", STDOUT_FILENO);
	rr(v);
	return (1);
}
