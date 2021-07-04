/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_arraydup.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/13 11:59:09 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/06/30 22:43:20 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ext.h"

char	**ft_arraydup(char **array, size_t size)
{
	char	**dst;
	size_t	i;

	if (!array)
		return (NULL);
	if (!size)
		size = ft_array_size((void **)array);
	dst = ft_calloc((size + 1), sizeof(char *));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < size && array[i] != NULL)
	{
		dst[i] = ft_strdup(array[i]);
		if (!dst[i])
			return (ft_free_array((void **)dst, i));
		i++;
	}
	return (dst);
}
