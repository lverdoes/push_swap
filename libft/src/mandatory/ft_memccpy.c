/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 12:58:00 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/02/05 19:09:09 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ret;
	size_t			i;

	ret = dst;
	i = 0;
	while (i < n)
	{
		ret[i] = ((unsigned char *)src)[i];
		if (ret[i] == (unsigned char)c)
			return (ret + i + 1);
		i++;
	}
	return (NULL);
}
