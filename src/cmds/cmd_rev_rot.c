/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_rev_rot.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 16:06:46 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/30 17:09:29 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "unistd.h"
#include "libft.h"

int	cmd_rra(t_vars *v)
{
	if (v->opt.color)
		ft_putendl_fd(COLOR_RRA, v->opt.instr_fd);
	else
		ft_putendl_fd("rra", v->opt.instr_fd);
	rra(v);
	return (1);
}

int	cmd_rrb(t_vars *v)
{
	if (v->opt.color)
		ft_putendl_fd(COLOR_RRB, v->opt.instr_fd);
	else
		ft_putendl_fd("rrb", v->opt.instr_fd);
	rrb(v);
	return (1);
}

int	cmd_rrr(t_vars *v)
{
	if (v->opt.color)
		ft_putendl_fd(COLOR_RRR, v->opt.instr_fd);
	else
		ft_putendl_fd("rrr", v->opt.instr_fd);
	rrr(v);
	return (1);
}
