/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_instruction.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 19:46:11 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/07 22:25:22 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	read_instruction(t_vars *v, char const *const line)
{	//https://www.sanfoundry.com/c-tutorials-jump-tables/
	if (!ft_strncmp(line, "sa", 3))
		sa(v);
	else if (!ft_strncmp(line, "sb", 3))
		sb(v);
	else if (!ft_strncmp(line, "ss", 3))
		ss(v);
	else if (!ft_strncmp(line, "pa", 3))
		pa(v);
	else if (!ft_strncmp(line, "pb", 3))
		pb(v);
	else if (!ft_strncmp(line, "ra", 3))
		ra(v);
	else if (!ft_strncmp(line, "rb", 3))
		rb(v);
	else if (!ft_strncmp(line, "rr", 3))
		rr(v);
	else if (!ft_strncmp(line, "rra", 4))
		rra(v);
	else if (!ft_strncmp(line, "rrb", 4))
		rrb(v);
	else if (!ft_strncmp(line, "rrr", 4))
		rrr(v);
	else
		ft_exit("Error");
}
