/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_realloc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 14:17:12 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/06 11:13:39 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy_ptrs(char **dst, char **src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
}

char	**ft_realloc(char **src, const char *line, size_t *size)
{
	char	**dst;
	size_t	array_size;

	array_size = ft_array_size(src);
	dst = ft_calloc(array_size + 2, sizeof(char *));
	if (!dst)
		return (ft_free_char(src, array_size));
	copy_ptrs(dst, src, array_size);
	ft_free(src);
	dst[array_size] = ft_strdup(line);
	if (!dst[array_size])
		return (ft_free_char(dst, array_size));
	if (size)
		*size = array_size + 1;
	return (dst);
}
