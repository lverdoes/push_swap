/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_color_instructions.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 15:42:59 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/05/01 00:29:16 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

int	read_color_instruction(t_vars *v, char *line)
{
	if (!ft_strncmp(line, COLOR_SA, ft_strlen(COLOR_SA) + 1))
		return (sa(v));
	else if (!ft_strncmp(line, COLOR_SB, ft_strlen(COLOR_SB) + 1))
		return (sb(v));
	else if (!ft_strncmp(line, COLOR_SS, ft_strlen(COLOR_SS) + 1))
		return (ss(v));
	else if (!ft_strncmp(line, COLOR_PA, ft_strlen(COLOR_PA) + 1))
		return (pa(v));
	else if (!ft_strncmp(line, COLOR_PB, ft_strlen(COLOR_PB) + 1))
		return (pb(v));
	else if (!ft_strncmp(line, COLOR_RA, ft_strlen(COLOR_RA) + 1))
		return (ra(v));
	else if (!ft_strncmp(line, COLOR_RB, ft_strlen(COLOR_RB) + 1))
		return (rb(v));
	else if (!ft_strncmp(line, COLOR_RR, ft_strlen(COLOR_RR) + 1))
		return (rr(v));
	else if (!ft_strncmp(line, COLOR_RRA, ft_strlen(COLOR_RRA) + 1))
		return (rra(v));
	else if (!ft_strncmp(line, COLOR_RRB, ft_strlen(COLOR_RRB) + 1))
		return (rrb(v));
	else if (!ft_strncmp(line, COLOR_RRR, ft_strlen(COLOR_RRR) + 1))
		return (rrr(v));
	return (ft_exit(ERROR));
}
