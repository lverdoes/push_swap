/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_dup.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/05 11:55:57 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/05/26 09:40:27 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

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
**
**	int	intcmp(t_elem *a, t_elem *b)
**	{
**		return (a->num - b->num);
**	}
**
*/

static t_list	*clean_up(t_list *dup_h, t_list *dup_c, void (*del)(void *))
{
	if (dup_c)
		del(dup_c);
	ft_list_del_all(&dup_h, del);
	return (NULL);
}

t_list	*ft_list_dup(t_list *head, void *(*dup)(void *), void (*del)(void *))
{
	t_list	*dup_head;
	void	*dup_content;
	t_list	*new;
	t_list	*tmp;

	dup_head = NULL;
	tmp = head;
	while (tmp)
	{
		dup_content = dup(tmp->content);
		if (!dup_content)
			return (clean_up(dup_head, dup_content, del));
		new = ft_list_new(dup_content);
		if (!new)
			return (clean_up(dup_head, dup_content, del));
		ft_list_add_back(&dup_head, new);
		tmp = tmp->next;
	}
	return (dup_head);
}
