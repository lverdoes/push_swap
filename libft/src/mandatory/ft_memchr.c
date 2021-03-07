/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 16:26:16 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/02/26 15:09:02 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ret;
	size_t			i;

	ret = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ret[i] == (unsigned char)c)
			return (ret + i);
		i++;
	}
	return (NULL);
}
