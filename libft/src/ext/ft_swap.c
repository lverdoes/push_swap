/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_swap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 09:21:18 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/02/26 15:27:36 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_swap(void *a, void *b, size_t size_of_data_type)
{
	size_t			i;
	unsigned char	*arg1;
	unsigned char	*arg2;

	i = 0;
	arg1 = a;
	arg2 = b;
	while (i < size_of_data_type)
	{
		arg1[i] = arg1[i] ^ arg2[i];
		arg2[i] = arg1[i] ^ arg2[i];
		arg1[i] = arg1[i] ^ arg2[i];
		i++;
	}
}
