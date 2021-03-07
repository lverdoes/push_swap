/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_node_join.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 10:18:15 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/02/05 19:14:41 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_node_join(t_node *left, t_node *right)
{
	left->next = right;
	right->prev = left;
}
