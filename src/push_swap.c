/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 22:00:06 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/04 00:30:31 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	solve(t_vars *v)
{
	if (finished(&v->a, &v->b))
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
	init(&v, v.args.size, v.args.args);
	solve(&v);
	return (ft_exit(NULL));
}
