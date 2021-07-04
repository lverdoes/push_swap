/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_realloc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 14:17:12 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/06/08 13:03:54 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ext.h"

static void	copy_ptrs(void **dst, void **src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
}

void	**ft_realloc(void **src, void *ptr, size_t *size)
{
	void	**dst;
	size_t	array_size;

	array_size = ft_array_size(src);
	dst = ft_calloc(array_size + 2, sizeof(void *));
	if (!dst)
		return (NULL);
	copy_ptrs(dst, src, array_size);
	dst[array_size] = ptr;
	if (size)
		*size = array_size + 1;
	return (dst);
}
