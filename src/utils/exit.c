/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 20:21:32 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/04 09:02:23 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

int	ft_exit(char *str)
{
	if (str)
		ft_putendl_fd(str, STDERR_FILENO);
	exit(0);
	return (0);
}

void	check_malloc(void *ptr)
{
	if (!ptr)
		ft_exit(ERROR);
}
