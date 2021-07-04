/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split_strnstr.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/04 09:01:25 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/06/08 13:02:54 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ext.h"

static size_t	get_start(const char *src, const char *set, size_t i)
{
	char	*ptr;

	ptr = ft_strnstr(src + i, set, ft_strlen(src));
	if (!ptr)
		return (i);
	if (i == 0 && ptr > src)
		return (0);
	i = ptr - src + ft_strlen(set);
	return (i);
}

static size_t	get_len(const char *src, const char *set, size_t start)
{
	char	*ptr;

	ptr = ft_strnstr(src + start, set, ft_strlen(src));
	if (ptr)
		return (ptr - (src + start));
	return (ft_strlen(src + start));
}

static size_t	count_strings(const char *src, const char *set)
{
	size_t	count;
	size_t	len_src;
	size_t	len_set;
	char	*ptr;
	size_t	i;

	len_set = ft_strlen(set);
	len_src = ft_strlen(src);
	ptr = ft_strnstr(src, set, len_src);
	if (!ptr)
		return (1);
	count = 0;
	if (ptr != src)
		count++;
	i = ptr - src + len_set;
	while (ptr)
	{
		if (ft_strnstr(src + i, set, len_set) != ptr + i)
			count++;
		ptr = ft_strnstr(src + i, set, len_src);
		if (!ptr)
			return (count);
		i = ptr - src + len_set;
	}
	return (count);
}

static int	init_dst(char **dst, const char *src, const char *set, size_t size)
{
	size_t	i;
	size_t	start;
	size_t	len;

	i = 0;
	start = 0;
	len = 0;
	while (i < size)
	{
		start = get_start(src, set, start + len);
		len = get_len(src, set, start);
		dst[i] = ft_substr(src, start, len);
		if (!dst[i])
			return ((int)ft_free_array((void **)dst, i));
		i++;
	}
	return (1);
}

char	**ft_split_strnstr(const char *src, const char *set, size_t *size)
{
	char	**dst;
	size_t	array_size;

	if (!src)
		return (NULL);
	array_size = count_strings(src, set);
	dst = ft_calloc((array_size + 1), sizeof(char *));
	if (!dst)
		return (NULL);
	if (!init_dst(dst, src, set, array_size))
		return (NULL);
	if (size)
		*size = array_size;
	return (dst);
}
