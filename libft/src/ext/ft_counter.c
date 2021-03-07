/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_counter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/08 10:29:48 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/02/26 15:21:50 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_counter(const char *s, const char *set)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (ft_strchr(set, s[i]))
			count++;
		i++;
	}
	return (count);
}
