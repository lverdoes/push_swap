/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str_to_lower.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/21 12:40:37 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/02/26 15:23:59 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_str_to_lower(char *str)
{
	size_t	i;

	if (!str)
		return ;
	i = 0;
	while (str[i] != '\0')
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
}
