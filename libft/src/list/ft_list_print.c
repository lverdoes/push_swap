/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_print.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 08:06:50 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/05/26 09:55:01 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_list.h"

/*
**	Prints content of all lists in a linked list. Specifics and format are
**	determined in void (*print)()
**	
**	Example: a print function with list->content of t_var
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

static void	put_indentation_space(size_t i, size_t len, int fd)
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
		ft_putchar_fd(' ', fd);
		spaces--;
	}
}

void	ft_list_print(t_list *list, void (*print_function)(), int fd)
{
	size_t	len;
	size_t	i;
	t_list	*tmp;

	len = ft_list_size(list);
	i = 0;
	tmp = list;
	while (tmp)
	{
		ft_putstr_fd("list nr: [", fd);
		put_indentation_space(i, len, fd);
		ft_putnbr_fd((int)i, fd);
		ft_putendl_fd("]", fd);
		print_function(tmp->content, fd);
		i++;
		tmp = tmp->next;
	}
}
