/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_duplicate.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 19:39:45 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/04 01:27:12 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

static void	insert_sort(t_node **head, t_node *node, int (*cmp)())
{
	t_node	*tmp;

	tmp = *head;
	while (tmp)
	{
		if (cmp(node->content, tmp->content) == 0)
			ft_exit("Error");
		if (cmp(node->content, tmp->content) < 0)
		{
			ft_node_insert_before(head, node, tmp);
			return ;
		}
		tmp = tmp->next;
	}
	ft_node_add_back(head, node);
}

void	check_duplicate(t_vars *v, int num)
{
	t_node	*new;
	t_elem	*dup;

	dup = ft_calloc(1, sizeof(t_elem));
	check_malloc(dup);
	new = ft_node_new(dup);
	check_malloc(new);
	dup->num = num;
	insert_sort(&v->sorted, new, intcmp);
}
