/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_push_swap.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 22:00:06 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/07 22:21:36 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_vars	v;
	t_args	a;

	check_args(&a, argc, argv);
	init(&v, a.size, a.args);
	solve(&v);
	return (0);
}
