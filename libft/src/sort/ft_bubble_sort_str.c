/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bubble_sort_str.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/05 21:10:38 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/04 01:03:40 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bubble_sort_str(char **array, size_t *array_size)
{
	size_t	i;
	size_t	j;
	size_t	size;

	if (!array_size)
		size = ft_array_size(array);
	else
		size = *array_size;
	if (size < 2)
		return ;
	size -= 1;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - i)
		{
			if (ft_strncmp(array[j], array[j + 1], ft_strlen(array[j]) + 1) > 0)
				ft_swap(&array[j], &array[j + 1], sizeof(char *));
			j++;
		}
		i++;
	}
}
