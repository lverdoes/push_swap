/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_join.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/29 10:18:15 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/05/26 09:41:52 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_join(t_list *left, t_list *right)
{
	left->next = right;
	right->prev = left;
}
