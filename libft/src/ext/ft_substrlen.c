/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substrlen.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/02 17:21:35 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/02/26 15:24:26 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_substrlen(const char *str, const char *set)
{
	size_t	i;

	if (!set)
		return (ft_strlen(str));
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_strchr(set, str[i]))
			return (i);
		i++;
	}
	return (i);
}
