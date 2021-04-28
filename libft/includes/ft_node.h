/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_node.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/07 11:22:52 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/07 13:04:48 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NODE_H
# define FT_NODE_H

# include <stddef.h>

typedef struct s_node
{
	void			*content;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

void	ft_node_add_back(t_node **head, t_node *new_node);
void	ft_node_add_front(t_node **head, t_node *new_node);
void	ft_node_combine(t_node **head, t_node *right, int (*cmp)());
void	ft_node_del_all(t_node **head, void (*del)(void *));
void	ft_node_del_one(t_node *node, void (*del)(void *));
t_node	*ft_node_dup(t_node *head, void *(*dup)(void *), void (*del)(void *));
t_node	*ft_node_find(t_node *start, void *data_ref, int (*cmp)());
void	ft_node_insert_after(t_node **head, t_node *node, t_node *after_this);
void	ft_node_insert_before(t_node **head, t_node *node, t_node *before_this);
void	ft_node_insert_sort(t_node **head, t_node *node, int (*cmp)());
int		ft_node_is_sorted(t_node **head, int (*cmp)());
void	ft_node_iter(t_node *node, void (*f)(void *));
size_t	ft_node_index(t_node *start, void *data_ref, int (*cmp)());
void	ft_node_join(t_node *left, t_node *right);
t_node	*ft_node_last(t_node *node);
t_node	*ft_node_new(void *content);
t_node	*ft_node_number(t_node *node, size_t number);
void	ft_node_remove_if(t_node **head, void *data_ref, \
		int (*cmp)(), void (*del)(void *));
void	ft_node_remove_one(t_node **head, t_node *node, void (*del)(void *));
size_t	ft_node_size(t_node *node);
void	ft_node_sort(t_node *head, int (*cmp)());
t_node	*ft_node_unlink(t_node **head, t_node *node);
void	ft_print_node_list(t_node *node, void (*print)());

#endif
