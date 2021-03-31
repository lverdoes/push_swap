/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_node_merge.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 10:12:42 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/11 17:32:08 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	add_remaining(t_node *left, t_node *right, t_node *last_sorted)
{
	if (right)
		ft_node_join(last_sorted, right);
	else if (left)
		ft_node_join(last_sorted, left);
}

static void	set_head(t_node **head, t_node **left, t_node **right, int (*cmp)())
{
	t_node	*tmp;

	if (cmp((*head)->content, (*right)->content) > 0)
	{
		tmp = (*right)->next;
		ft_node_add_front(head, (*right));
		(*right) = tmp;
	}
	else
		(*left) = (*left)->next;
}

void	ft_node_merge(t_node **head, t_node *right, int (*cmp)())
{
	t_node	*left;
	t_node	*tmp;
	t_node	*last_sorted;

	left = *head;
	set_head(head, &left, &right, cmp);
	last_sorted = *head;
	while (left && right)
	{
		if (cmp(left->content, right->content) < 0)
		{
			last_sorted = left;
			left = left->next;
		}
		else
		{
			tmp = right->next;
			ft_node_insert_after(head, right, last_sorted);
			last_sorted = right;
			right = tmp;
		}
	}
	add_remaining(left, right, last_sorted);
}
