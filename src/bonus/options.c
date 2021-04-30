/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   options.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:57:43 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/05/01 00:29:16 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int	get_option(t_vars *v, char *str)
{
	int	i;

	if (str[1] == '\0')
		ft_exit(ERROR);
	i = 1;
	while (str[i])
	{
		if (str[i] == 'h')
			return (option_help());
		else if (str[i] == 'd')
			v->opt.data = TRUE;
		else if (str[i] == 'v')
			v->opt.verbose = TRUE;
		else if (str[i] == 'c')
			v->opt.color = TRUE;
		else if (str[i] == 'f')
			v->opt.file = TRUE;
		else if (str[i] == 'o')
			v->opt.instr = TRUE;
		else
			ft_exit(ERROR);
		i++;
	}
	return (0);
}

int	search_options(t_vars *v, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			if (ft_isdigit(argv[i][1]))
				return (i);
			get_option(v, argv[i]);
		}
		else
			return (i);
		i++;
	}
	return (i);
}

int	file_option(t_vars *v, char **argv, int i, char **str)
{
	int	fd;

	fd = open(argv[i], O_RDONLY);
	if (fd < 0)
		ft_exit(ERROR);
	if (ft_getline(fd, str) < 0)
		ft_exit(ERROR);
	close(fd);
	(void)v;
	return (1);
}

int	cmd_file_option(t_vars *v, char **argv, int i)
{
	if (!ft_strncmp(argv[0], "./checker", 10))
		v->opt.instr_fd = open(argv[i], O_RDONLY);
	else
		v->opt.instr_fd = open(argv[i], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (v->opt.instr_fd < 0)
		ft_exit(ERROR);
	return (0);
}
