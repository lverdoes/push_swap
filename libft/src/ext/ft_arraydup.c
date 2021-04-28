/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_arraydup.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/13 11:59:09 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/08 23:42:42 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ext.h"

static char	**free_array(char **dst, size_t i)
{
	while (i > 0)
	{
		i--;
		ft_free(dst[i]);
	}
	ft_free(dst);
	return (NULL);
}

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
			return (free_array(dst, i));
		i++;
	}
	return (dst);
}
