/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 11:22:52 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/05/26 09:54:39 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stddef.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

void	ft_list_add_back(t_list **head, t_list *new_list);
void	ft_list_add_front(t_list **head, t_list *new_list);
void	ft_list_combine(t_list **head, t_list *right, int (*cmp)());
void	ft_list_del_all(t_list **head, void (*del)(void *));
void	ft_list_del_one(t_list *list, void (*del)(void *));
t_list	*ft_list_dup(t_list *head, void *(*dup)(void *), void (*del)(void *));
t_list	*ft_list_find(t_list *start, void *data_ref, int (*cmp)());
size_t	ft_list_index(t_list *start, void *data_ref, int (*cmp)());
void	ft_list_insert_after(t_list **head, t_list *list, t_list *after_this);
void	ft_list_insert_before(t_list **head, t_list *list, t_list *before_this);
void	ft_list_insert_sort(t_list **head, t_list *list, int (*cmp)());
int		ft_list_is_sorted(t_list **head, int (*cmp)());
void	ft_list_iter(t_list *list, void (*f)(void *));
void	ft_list_join(t_list *left, t_list *right);
t_list	*ft_list_last(t_list *list);
t_list	*ft_list_new(void *content);
t_list	*ft_list_number(t_list *list, size_t number);
void	ft_list_print(t_list *list, void (*print)(), int fd);
void	ft_list_remove_if(t_list **head, void *data_ref, int (*cmp)(), void (*del)(void *));
void	ft_list_remove_one(t_list **head, t_list *list, void (*del)(void *));
size_t	ft_list_size(t_list *list);
void	ft_list_sort(t_list *head, int (*cmp)());
t_list	*ft_list_unlink(t_list **head, t_list *list);

#endif
