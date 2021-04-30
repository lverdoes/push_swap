/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_push_swap.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 16:04:50 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/30 17:09:06 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

int	cmd_sa(t_vars *v)
{
	if (v->opt.color)
		ft_putendl_fd(COLOR_SA, v->opt.instr_fd);
	else
		ft_putendl_fd("sa", v->opt.instr_fd);
	sa(v);
	return (1);
}

int	cmd_sb(t_vars *v)
{
	if (v->opt.color)
		ft_putendl_fd(COLOR_SB, v->opt.instr_fd);
	else
		ft_putendl_fd("sb", v->opt.instr_fd);
	sb(v);
	return (1);
}

int	cmd_ss(t_vars *v)
{
	if (v->opt.color)
		ft_putendl_fd(COLOR_SS, v->opt.instr_fd);
	else
		ft_putendl_fd("ss", v->opt.instr_fd);
	ss(v);
	return (1);
}

int	cmd_pa(t_vars *v)
{
	if (v->opt.color)
		ft_putendl_fd(COLOR_PA, v->opt.instr_fd);
	else
		ft_putendl_fd("pa", v->opt.instr_fd);
	pa(v);
	return (1);
}

int	cmd_pb(t_vars *v)
{
	if (v->opt.color)
		ft_putendl_fd(COLOR_PB, v->opt.instr_fd);
	else
		ft_putendl_fd("pb", v->opt.instr_fd);
	pb(v);
	return (1);
}
