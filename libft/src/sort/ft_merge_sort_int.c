/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_merge_sort_int.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/05 21:29:49 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/02/26 15:56:17 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_left_or_right(t_merge *m, size_t i, size_t j)
{
	if (j == m->len_r)
		return (1);
	if (i < m->len_l && ((int *)m->left)[i] <= ((int *)m->right)[j])
		return (1);
	return (0);
}

static void	merge_arrays(t_merge *m, int *array, size_t start)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = start;
	while (i + j < m->total_len)
	{
		if (get_left_or_right(m, i, j))
		{
			array[k] = ((int *)m->left)[i];
			i++;
		}
		else
		{
			array[k] = ((int *)m->right)[j];
			j++;
		}
		k++;
	}
}

static int	init(int *array, size_t start, size_t middle, size_t end)
{
	t_merge	merge;

	merge.array = array;
	merge.len_l = middle - start + 1;
	merge.len_r = end - middle;
	merge.total_len = end - start + 1;
	merge.left = ft_intdup(array + start, merge.len_l);
	if (!merge.left)
		return (0);
	merge.right = ft_intdup(array + middle + 1, merge.len_r);
	if (!merge.right)
		return (ft_free((void *)merge.left));
	merge_arrays(&merge, merge.array, start);
	ft_free(merge.left);
	ft_free(merge.right);
	return (1);
}

static int	divide_array_in_two(int *array, size_t start, size_t end)
{
	size_t	middle;

	middle = start + (end - start) / 2;
	if (start < end)
	{
		if (!divide_array_in_two(array, start, middle))
			return (0);
		if (!divide_array_in_two(array, middle + 1, end))
			return (0);
		if (!init(array, start, middle, end))
			return (0);
	}
	return (1);
}

int	ft_merge_sort_int(int *array, size_t len)
{
	if (len < 2)
		return (1);
	return (divide_array_in_two(array, 0, len - 1));
}
