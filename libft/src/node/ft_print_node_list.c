/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_node_list.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 08:06:50 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/07 11:38:13 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_node.h"

/*
**	Prints content of all nodes in a linked list. Specifics and format are
**	determined in void (*print)()
**	
**	Example: a print function with node->content of t_var
**
**	typedef struct	s_var{
**		int			num;
**		char		*str;
**	}				t_var;
**
**	void	print_var(t_var *var)
**	{
**		ft_putstr_fd("num: ", 1);
**		ft_putnbr_fd(var->num, 1);
**		ft_putchar_fd('\n', 1);
**		ft_putstr_fd("str: ", 1);
**		ft_putendl_fd(var->str, 1);
**	}
**	
*/

static size_t	get_magnitude(size_t num)
{
	size_t	ret;

	ret = 1;
	while (num > 9)
	{
		num = num / 10;
		ret++;
	}
	return (ret);
}

static void	put_indentation_space(size_t i, size_t len)
{
	size_t	magnitude_len;
	size_t	magnitude_i;
	size_t	spaces;

	len--;
	magnitude_len = get_magnitude(len);
	magnitude_i = get_magnitude(i);
	spaces = magnitude_len - magnitude_i;
	while (spaces > 0)
	{
		ft_putchar_fd(' ', 1);
		spaces--;
	}
}

void	ft_print_node_list(t_node *node, void (*print)())
{
	size_t	len;
	size_t	i;
	t_node	*tmp;

	len = ft_node_size(node);
	i = 0;
	tmp = node;
	while (tmp)
	{
		ft_putstr_fd("Node nr: [", 1);
		put_indentation_space(i, len);
		ft_putnbr_fd((int)i, 1);
		ft_putendl_fd("]", 1);
		print(tmp->content, 1);
		i++;
		tmp = tmp->next;
	}
}
