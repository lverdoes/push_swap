/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 22:00:06 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/05/01 18:33:20 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"
#include "ft_ext.h"
#include <stdlib.h>

static int	solve(t_vars *v)
{
	if (finished(v))
		return (1);
	if (v->total_size > HUGE)
		return (solve_huge(v));
	if (v->total_size > LARGE)
		return (solve_large(v));
	if (v->total_size > MEDIUM)
		return (solve_medium(v, 2));
	return (solve_small(v));
}

int	main(int argc, char **argv)
{
	t_vars	v;

	ft_bzero(&v, sizeof(t_vars));
	check_args(&v, argc, argv);
	init_stacks(&v, v.args.size, v.args.args);
	if (!v.opt.instr)
		v.opt.instr_fd = 1;
	solve(&v);
	exit(0);
	return (0);
}
