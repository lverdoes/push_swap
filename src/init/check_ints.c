/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_ints.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 19:39:45 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/12 10:20:42 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
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

static void	insert_sort(t_list **head, t_list *list, int (*cmp)())
{
	t_list	*tmp;

	tmp = *head;
	while (tmp)
	{
		if (cmp(list->content, tmp->content) == 0)
			ft_exit(ERROR);
		if (cmp(list->content, tmp->content) < 0)
		{
			ft_list_insert_before(head, list, tmp);
			return ;
		}
		tmp = tmp->next;
	}
	ft_list_add_back(head, list);
}

void	check_duplicate(t_vars *v, int num, t_list **head_sorted)
{
	t_list	*new;
	t_elem	*dup;

	dup = ft_calloc(1, sizeof(t_elem));
	check_malloc(dup);
	new = ft_list_new(dup);
	check_malloc(new);
	dup->num = num;
	insert_sort(head_sorted, new, intcmp);
}
