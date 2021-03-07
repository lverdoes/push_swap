/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_array.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/16 13:42:00 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/02/26 15:25:37 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_free_ptr(void *ptr)
{
	free(ptr);
	return (NULL);
}

char	**ft_free_char(char **array, size_t i)
{
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
	return (NULL);
}

int	ft_free(void *ptr)
{
	free(ptr);
	return (0);
}

int	ft_free_int(void *ptr, int ret)
{
	free(ptr);
	return (ret);
}

int	ft_free_array(void **array, size_t i)
{
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
	return (0);
}
