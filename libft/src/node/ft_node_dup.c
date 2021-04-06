/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_node_dup.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/05 11:55:57 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/06 13:04:17 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	typedef struct s_elem
**	{
**		int num;
**		char	*str;
**	}	t_elem;
**	
**	void	print_elem(t_elem *e)
**	{
**		ft_putendl_fd(e->str, 1);
**	}
**	
**	t_elem	*create_elem(int num, char *str)
**	{
**		t_elem	*e;
**	
**		e = ft_calloc(1, sizeof(t_elem));
**		e->num = num;
**		e->str = ft_strdup(str);
**		return (e);
**	}
**	
**	void	delete_elem(void *ptr)
**	{
**		t_elem	*e;
**	
**		e = ptr;
**		ft_free(e->str);
**		ft_free(e);
**	}
**	
**	void	*ft_dup(void *ptr)
**	{
**		t_elem	*dst;
**		t_elem	*src;
**		
**		src = ptr;
**		dst = create_elem(src->num, src->str);
**		if (!dst)
**			return (NULL);
**		return (dst);
**	}
*/

static t_node	*clean_up(t_node *dup_h, t_node *dup_c, void (*del)(void *))
{
	if (dup_c)
		del(dup_c);
	ft_node_del_all(&dup_h, del);
	return (NULL);
}

t_node	*ft_node_dup(t_node *head, void *(*dup)(void *), void (*del)(void *))
{
	t_node	*dup_head;
	void	*dup_content;
	t_node	*new;
	t_node	*tmp;

	dup_head = NULL;
	tmp = head;
	while (tmp)
	{
		dup_content = dup(tmp->content);
		if (!dup_content)
			return (clean_up(dup_head, dup_content, del));
		new = ft_node_new(dup_content);
		if (!new)
			return (clean_up(dup_head, dup_content, del));
		ft_node_add_back(&dup_head, new);
		tmp = tmp->next;
	}
	return (dup_head);
}
