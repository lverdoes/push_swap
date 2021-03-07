/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_merge_sort_str.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/05 21:27:33 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/04 01:03:55 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_left_or_right(t_merge *m, size_t i, size_t j)
{
	char	*left;
	char	*right;

	if (j == m->len_r)
		return (1);
	if (i == m->len_l)
		return (0);
	left = ((char **)m->left)[i];
	right = ((char **)m->right)[j];
	return (ft_strcmp(left, right) <= 0);
}

static void	merge_arrays(t_merge *merge, char **array, size_t start)
{
	t_merge	*m;
	size_t	i;
	size_t	j;
	size_t	k;

	m = merge;
	i = 0;
	j = 0;
	k = start;
	while (i + j < m->total_len)
	{
		ft_free(array[k]);
		if (get_left_or_right(m, i, j))
		{
			array[k] = ((char **)m->left)[i];
			i++;
		}
		else
		{
			array[k] = ((char **)m->right)[j];
			j++;
		}
		k++;
	}
}

static int	init(char **array, size_t start, size_t middle, size_t end)
{
	t_merge	merge;

	merge.array = array;
	merge.len_l = middle - start + 1;
	merge.len_r = end - middle;
	merge.total_len = end - start + 1;
	merge.left = ft_arraydup(array + start, merge.len_l);
	if (!merge.left)
		return (0);
	merge.right = ft_arraydup(array + middle + 1, merge.len_r);
	if (!merge.right)
		return (ft_free_array((void **)merge.left, merge.len_r));
	merge_arrays(&merge, merge.array, start);
	ft_free(merge.left);
	ft_free(merge.right);
	return (1);
}

static int	divide_array_in_two(char **array, size_t start, size_t end)
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

int	ft_merge_sort_str(char **array, size_t *array_size)
{
	size_t	end;

	if (!array_size)
		end = ft_array_size(array);
	else
		end = *array_size;
	if (end < 2)
		return (1);
	return (divide_array_in_two(array, 0, end - 1));
}
