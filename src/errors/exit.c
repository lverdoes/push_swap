/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 20:21:32 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/30 18:52:10 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

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
		ft_exit("Error");
}
