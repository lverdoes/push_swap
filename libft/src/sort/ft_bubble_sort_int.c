/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bubble_sort_int.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/02 07:18:11 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/02/26 15:14:37 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bubble_sort_int(int *array, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (array[i] < array[j])
				ft_swap(&array[i], &array[j], sizeof(int));
			j++;
		}
		i++;
	}
}
