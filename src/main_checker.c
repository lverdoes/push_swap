/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_checker.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 15:23:36 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/07 22:22:27 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_vars	v;
	t_args	a;
	int		ret;
	char	*line;

	check_args(&a, argc, argv);
	init(&v, a.size, a.args);
	ret = 1;
	while (ret == 1)
	{
		ret = get_next_line(STDIN, &line);
		if (ret < 0)
			ft_exit("Error");
		if (ret == 0)
			break ;
		if (*line != '\0')
			read_instruction(&v, line);
		ft_free(line);
	}
	if (finished(&v))
		ft_exit("OK");
	ft_exit("KO");
	return (0);
}