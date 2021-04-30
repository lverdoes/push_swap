/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_bonus.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 21:25:33 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/05/01 00:29:16 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"
#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

static void	init_variables(t_vars *v, int argc, char **argv, int *const ret)
{
	ft_bzero(v, sizeof(t_vars));
	check_args(v, argc, argv);
	init_stacks(v, v->args.size, v->args.args);
	if (!v->opt.instr)
		v->opt.instr_fd = 0;
	*ret = 1;
}

int	main(int argc, char **argv)
{
	t_vars	v;
	int		ret;
	char	*line;

	init_variables(&v, argc, argv, &ret);
	while (ret == 1)
	{
		ret = get_next_line(v.opt.instr_fd, &line);
		if (ret < 0)
			ft_exit(ERROR);
		if (*line != '\0')
			read_instruction(&v, line);
		if (v.opt.verbose)
			print_stacks(&v, line);
		free(line);
	}
	close(v.opt.instr_fd);
	if (v.opt.data)
		print_data(&v);
	if (finished(&v))
		ft_exit("OK");
	ft_exit("KO");
}
