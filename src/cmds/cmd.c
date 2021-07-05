/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/03 11:55:50 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/07/05 15:02:22 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "instructions.h"
#include "libft.h"
#include <unistd.h>

int	cmd_pa(t_vars *v)
{
	ft_putendl_fd("pa", STDOUT_FILENO);
	pa(v);
	return (0);
}

int	cmd_pb(t_vars *v)
{
	ft_putendl_fd("pb", STDOUT_FILENO);
	pb(v);
	return (0);
}

int	cmd_sa(t_vars *v)
{
	ft_putendl_fd("sa", STDOUT_FILENO);
	sa(v);
	return (0);
}

int	cmd_sb(t_vars *v)
{
	ft_putendl_fd("sb", STDOUT_FILENO);
	sb(v);
	return (0);
}

int	cmd_ss(t_vars *v)
{
	ft_putendl_fd("ss", STDOUT_FILENO);
	ss(v);
	return (0);
}

int	cmd_ra(t_vars *v)
{
	ft_putendl_fd("ra", STDOUT_FILENO);
	ra(v);
	return (0);
}

int	cmd_rb(t_vars *v)
{
	ft_putendl_fd("rb", STDOUT_FILENO);
	rb(v);
	return (0);
}

int	cmd_rr(t_vars *v)
{
	ft_putendl_fd("rr", STDOUT_FILENO);
	rr(v);
	return (0);
}

int	cmd_rra(t_vars *v)
{
	ft_putendl_fd("rra", STDOUT_FILENO);
	rra(v);
	return (0);
}

int	cmd_rrb(t_vars *v)
{
	ft_putendl_fd("rrb", STDOUT_FILENO);
	rrb(v);
	return (0);
}

int	cmd_rrr(t_vars *v)
{
	ft_putendl_fd("rrr", STDOUT_FILENO);
	rrr(v);
	return (0);
}

void	**cmd(t_cmd cmd, size_t amount)
{
	static t_vars	*ptr = NULL;
	size_t			i;

	if (!ptr)
		return ((void **)&ptr);
	i = 0;
	while (i < amount)
	{
		ptr->cmd[cmd](ptr);
		i++;
	}
	return (NULL);
}
