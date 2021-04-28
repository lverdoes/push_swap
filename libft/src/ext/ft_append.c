/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_append.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/09 20:45:32 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/07 12:37:21 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ext.h"

/*
**	s1:			The initial string that will be appended to.
**				If NULL, an empty string will be created.
**	s2:			The string to append to s1.
**	return:		After freeing s1, the combined string (dst) will be returned.
**				The return can be stored in the same var as param 1.
**				E.g.:	str = ft_append(str, ", ");
**				If NULL is returned, s1 has been freed.
*/

char	*ft_append(char *s1, const char *s2)
{
	char	*dst;
	size_t	len;

	if (!s1)
	{
		s1 = ft_strdup("\0");
		if (!s1)
			return (NULL);
	}
	if (!s2)
		return (s1);
	len = ft_strlen(s1) + ft_strlen(s2);
	dst = ft_calloc(len + 1, sizeof(char));
	if (!dst)
	{
		ft_free(s1);
		return (NULL);
	}
	ft_strlcat(dst, s1, len + 1);
	ft_strlcat(dst, s2, len + 1);
	ft_free(s1);
	return (dst);
}
