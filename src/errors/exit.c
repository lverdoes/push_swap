/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 20:21:32 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/27 18:12:25 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include "libft.h"
#include "ft_ext.h"

void	ft_exit(char *str)
{
	if (str)
		ft_putendl_fd(str, STDERR_FILENO);
	exit(0);
}

void	check_minmax_int(char *str)
{
	double	n;
	long	min;

	n = ft_atod(str);
	if (n > INT_MAX)
		ft_exit("Error");
	min = INT_MIN;
	if (n < min)
		ft_exit("Error");
}

void	check_digits(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (str[i] == '\0')
		ft_exit("Error");
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			ft_exit("Error");
		i++;
	}
}

void	check_malloc(void *ptr)
{
	if (!ptr)
		ft_exit("Error");
}
