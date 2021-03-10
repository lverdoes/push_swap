/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/04 10:35:22 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/09 22:39:59 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	solve(t_vars *v)
{
	if (finished(v))
		return (1);
	if (v->total_size > HUGE)
		return (solve_huge(v));
	if (v->total_size > LARGE)
		return (solve_large(v));
	if (v->total_size > MEDIUM)
		return (solve_medium(v));
	return (solve_small(v));
}