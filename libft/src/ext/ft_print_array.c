/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_array.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/24 11:12:42 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/06 11:13:15 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

void	ft_print_array(char **array)
{
	size_t	len;
	size_t	i;

	len = ft_array_size(array);
	i = 0;
	while (i < len)
	{
		ft_putchar_fd('[', 1);
		put_indentation_space(i, len);
		ft_putnbr_fd((int)i, 1);
		ft_putstr_fd("] ", 1);
		ft_putchar_fd('[', 1);
		ft_putstr_fd(array[i], 1);
		ft_putendl_fd("] ", 1);
		i++;
	}
}
