/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 15:23:36 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/05/01 00:29:16 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"
#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_vars	v;
	int		ret;
	char	*line;

	ft_bzero(&v, sizeof(t_vars));
	check_args(&v, argc, argv);
	init_stacks(&v, v.args.size, v.args.args);
	ret = 1;
	while (ret == 1)
	{
		ret = get_next_line(0, &line);
		if (ret < 0)
			ft_exit(ERROR);
		if (*line != '\0')
			read_instruction(&v, line);
		free(line);
	}
	if (finished(&v))
		ft_exit("OK");
	ft_exit("KO");
}