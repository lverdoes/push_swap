/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/31 16:20:04 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/31 16:20:06 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			ptr = (char *)s + i;
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	return (ptr);
}
