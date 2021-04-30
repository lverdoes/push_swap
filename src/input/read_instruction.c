/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_instruction.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 19:46:11 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/30 15:41:57 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

int	read_instruction(t_vars *v, char *line)
{
	if (v->opt.color)
		return (read_color_instruction(v, line));
	if (!ft_strncmp(line, "sa", 3))
		return (sa(v));
	else if (!ft_strncmp(line, "sb", 3))
		return (sb(v));
	else if (!ft_strncmp(line, "ss", 3))
		return (ss(v));
	else if (!ft_strncmp(line, "pa", 3))
		return (pa(v));
	else if (!ft_strncmp(line, "pb", 3))
		return (pb(v));
	else if (!ft_strncmp(line, "ra", 3))
		return (ra(v));
	else if (!ft_strncmp(line, "rb", 3))
		return (rb(v));
	else if (!ft_strncmp(line, "rr", 3))
		return (rr(v));
	else if (!ft_strncmp(line, "rra", 4))
		return (rra(v));
	else if (!ft_strncmp(line, "rrb", 4))
		return (rrb(v));
	else if (!ft_strncmp(line, "rrr", 4))
		return (rrr(v));
	return (ft_exit("Error instructions"));
}
