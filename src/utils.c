/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 15:37:22 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/29 23:03:15 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "ft_ext.h"

void	swap(t_elem *a, t_elem *b)
{
	ft_swap(a, b, sizeof(t_elem));
}

int	intcmp(t_elem *a, t_elem *b)
{
	if ((a->num) < (b->num))
		return (-1);
	if ((a->num) > (b->num))
		return (1);
	return (0);
}

int	rankcmp(int *ref, t_elem *e)
{
	return (*ref - e->rank);
}

int	finished(t_vars *v)
{
	if (!v->b.head && ft_node_is_sorted(&v->a.head, intcmp) == -1)
		return (1);
	return (0);
}
