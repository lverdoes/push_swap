/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_ints.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 19:39:45 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/05/01 00:30:34 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"
#include "ft_ext.h"
#include <limits.h>

void	check_minmax_int(char *str)
{
	double	n;
	long	min;

	n = ft_atod(str);
	if (n > INT_MAX)
		ft_exit(ERROR);
	min = INT_MIN;
	if (n < min)
		ft_exit(ERROR);
}

void	check_digits(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (str[i] == '\0')
		ft_exit(ERROR);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			ft_exit(ERROR);
		i++;
	}
}

static void	insert_sort(t_node **head, t_node *node, int (*cmp)())
{
	t_node	*tmp;

	tmp = *head;
	while (tmp)
	{
		if (cmp(node->content, tmp->content) == 0)
			ft_exit(ERROR);
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
