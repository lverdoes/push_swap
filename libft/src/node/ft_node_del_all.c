/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_node_del_all.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 23:36:17 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/06 11:19:13 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Delete the complete linked list.
**
**	Example of a DEL() function with a struct t_var:
**
**	typedef struct	s_var{
**		int			value;
**		char		*str;
**	}				t_var;
**	
**	void	del_var(void *var)
**	{
**		t_var *tmp;
**		
**		tmp = var;
**		free(tmp->str);
**		free(tmp);
**	}
**
**	Calling		'ft_node_del_all(&head, del_var);'	will delete the list
**
*/

void	ft_node_del_all(t_node **head, void (*del)(void *))
{
	t_node	*tmp;

	if (!head)
		return ;
	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		ft_node_del_one(tmp, del);
	}
	*head = NULL;
}
