/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 22:00:06 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/14 10:34:05 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	solve(t_vars *v)
{
	if (finished(&v->a, &v->b))
		return (1);
	if (v->total_size > 250)
		return (solve_huge49edit(v));
	if (v->total_size > 50)
		return (solve_large11(v));
	if (v->total_size > 5)
		return (solve_medium(&v->a, &v->b));
	return (solve_small(&v->a, &v->b));
}

int	main(int argc, char **argv)
{
	t_vars	v;

	ft_bzero(&v, sizeof(t_vars));
	check_args(&v, argc, argv);
	init(&v, v.args.size, v.args.args);
	solve(&v);
//	print_data(&v);
	return (ft_exit(NULL));
}
