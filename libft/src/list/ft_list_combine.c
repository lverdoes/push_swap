/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_combine.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 10:12:42 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/05/26 09:38:17 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static void	add_remaining(t_list *left, t_list *right, t_list *last_sorted)
{
	if (right)
		ft_list_join(last_sorted, right);
	else if (left)
		ft_list_join(last_sorted, left);
}

static void	set_head(t_list **head, t_list **left, t_list **right, int (*cmp)())
{
	t_list	*tmp;

	if (cmp((*head)->content, (*right)->content) > 0)
	{
		tmp = (*right)->next;
		ft_list_add_front(head, (*right));
		(*right) = tmp;
	}
	else
		(*left) = (*left)->next;
}

void	ft_list_merge(t_list **head, t_list *right, int (*cmp)())
{
	t_list	*left;
	t_list	*tmp;
	t_list	*last_sorted;

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
			ft_list_insert_after(head, right, last_sorted);
			last_sorted = right;
			right = tmp;
		}
	}
	add_remaining(left, right, last_sorted);
}
