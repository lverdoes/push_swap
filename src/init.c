/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 20:19:12 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/07 22:18:49 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_sorted(t_node *node)
{
	t_node	*tmp;
	t_elem	*e;

	tmp = node;
	while (tmp)
	{
		node = tmp;
		tmp = tmp->next;
		e = node->content;
		ft_free(e);
		ft_free(node);
	}
}

static size_t	node_index(t_node *start, void *data_ref, int (*cmp)())
{
	size_t	ret;
	t_node	*tmp;

	ret = 0;
	tmp = start;
	while (tmp)
	{
		if (!cmp(data_ref, tmp->content))
			break ;
		tmp = tmp->next;
		ret++;
	}
	return (ret);
}

static void	assign_rank(t_vars *v)
{
	t_node	*node;
	t_node	*tmp;
	t_elem	*elem;

	node = v->a;
	while (node)
	{
		elem = node->content;
		elem->rank = node_index(v->sorted, node->content, intcmp);
		tmp = node;
		node = node->next;
	}
}

void	init(t_vars *v, size_t size, char **args)
{
	t_node	*new;
	t_elem	*element;

	ft_bzero(v, sizeof(t_vars));
	while (size > 0)
	{
		size--;
		check_minmax_int(args[size]);
		check_digits(args[size]);
		element = ft_calloc(1, sizeof(t_elem));
		check_malloc(element);
		new = ft_node_new(element);
		check_malloc(new);
		element->num = ft_atoi(args[size]);
		check_duplicate(v, element->num);
		ft_node_add_front(&v->a, new);
	}
	assign_rank(v);
	free_sorted(v->sorted);
	v->total_size = ft_node_size(v->a);
	v->size_a = v->total_size;
	v->max_rank = v->total_size - 1;
}
