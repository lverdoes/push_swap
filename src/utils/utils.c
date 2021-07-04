/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 15:37:22 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/04 01:21:47 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_ext.h"

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

int	finished(t_stack *a, t_stack *b)
{
	if (!b->head && ft_list_is_sorted(&a->head, intcmp) == -1)
		return (1);
	return (0);
}
