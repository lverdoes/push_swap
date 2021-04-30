/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   options.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 12:57:43 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/30 17:07:41 by lverdoes      ########   odam.nl         */
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
		ft_exit("Error no option");
	i = 1;
	while (str[i])
	{
		if (str[i] == 'h')
			return (option_help(v));
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
			ft_exit("Error cmd option");
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

int	file_option(char **argv, int start, char **str)
{
	int	fd;

	if (!argv[start])
		ft_exit(NULL);
	fd = open(argv[start], O_RDONLY);
	if (fd < 0)
		ft_exit("Error file");
	if (ft_getline(fd, str) < 0)
		ft_exit("Error getline");
	close(fd);
	return (1);
}

int	cmd_file_option(t_vars *v, char **argv, int start)
{
	if (v->opt.file)
		start++;
	if (!argv[start])
		ft_exit(NULL);
	if (!ft_strncmp(argv[0], "./checker", 10))
		v->opt.instr_fd = open(argv[start], O_RDONLY);
	else
		v->opt.instr_fd = open(argv[start], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (v->opt.instr_fd < 0)
		ft_exit("Error cmdfile");
	return (0);
}
