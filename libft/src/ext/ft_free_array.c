/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_array.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/16 13:42:00 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/07 12:38:12 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_free(void *ptr)
{
	free(ptr);
	return (NULL);
}

int	ft_free1(void *ptr)
{
	free(ptr);
	return (0);
}

int	ft_free2(void **array, size_t i)
{
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
	return (0);
}
