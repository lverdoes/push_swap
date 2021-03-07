/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 14:31:55 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/02/26 15:22:09 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_intdup(int *src, size_t len)
{
	int		*dst;
	size_t	i;

	if (!src || !len)
		return (NULL);
	dst = ft_calloc(len, sizeof(int));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
