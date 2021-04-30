/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_rot.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 16:07:39 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/30 17:09:37 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "unistd.h"
#include "libft.h"

int	cmd_ra(t_vars *v)
{
	if (v->opt.color)
		ft_putendl_fd(COLOR_RA, v->opt.instr_fd);
	else
		ft_putendl_fd("ra", v->opt.instr_fd);
	ra(v);
	return (1);
}

int	cmd_rb(t_vars *v)
{
	if (v->opt.color)
		ft_putendl_fd(COLOR_RB, v->opt.instr_fd);
	else
		ft_putendl_fd("rb", v->opt.instr_fd);
	rb(v);
	return (1);
}

int	cmd_rr(t_vars *v)
{
	if (v->opt.color)
		ft_putendl_fd(COLOR_RR, v->opt.instr_fd);
	else
		ft_putendl_fd("rr", v->opt.instr_fd);
	rr(v);
	return (1);
}
