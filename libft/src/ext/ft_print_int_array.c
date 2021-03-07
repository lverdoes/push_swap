/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_int_array.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/03 18:05:22 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/02/26 15:22:49 by lverdoes      ########   odam.nl         */
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

void	ft_print_int_array(int *array, size_t size)
{
	size_t	i;

	if (size == 0)
		return ;
	i = 0;
	while (i < size)
	{
		ft_putchar_fd('[', 1);
		put_indentation_space(i, size);
		ft_putnbr_fd((int)i, 1);
		ft_putstr_fd("] ", 1);
		ft_putchar_fd('[', 1);
		ft_putnbr_fd(array[i], 1);
		ft_putendl_fd("] ", 1);
		i++;
	}
}
