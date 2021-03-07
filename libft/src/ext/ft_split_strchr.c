/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split_strchr.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 08:58:49 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/02/26 15:27:55 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_start(const char *src, const char *set, size_t i)
{
	while (src[i] != '\0' && ft_strchr(set, src[i]))
		i++;
	return (i);
}

static size_t	get_len(const char *src, const char *set, size_t start)
{
	size_t	i;
	size_t	len;

	i = start;
	len = 0;
	while (src[i] != '\0' && !ft_strchr(set, src[i]))
	{
		i++;
		len++;
	}
	return (len);
}

static size_t	count_strings(const char *src, const char *set)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (ft_strlen(set) == 0 && src[i] != '\0')
		return (1);
	while (src[i] != '\0')
	{
		if (!ft_strchr(set, src[i]))
		{
			count++;
			while (!ft_strchr(set, src[i]) && src[i] != '\0')
				i++;
		}
		while (ft_strchr(set, src[i]))
			i++;
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
			return (ft_free_array((void **)dst, i));
		i++;
	}
	return (1);
}

char	**ft_split_strchr(const char *src, const char *set, size_t *size)
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
