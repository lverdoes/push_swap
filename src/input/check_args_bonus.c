/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_args_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 21:23:41 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/05/01 00:29:16 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "ft_ext.h"
#include <stdlib.h>

static char	*append_to_str(char **array, char *str)
{
	char	*substr;

	substr = ft_concat_array(array, SPACE);
	check_malloc(substr);
	str = ft_append(str, SPACE);
	check_malloc(str);
	str = ft_append(str, substr);
	check_malloc(str);
	free(substr);
	return (str);
}

static char	*args_to_str(int argc, char **argv, int i)
{
	char	*str;
	char	**array;
	size_t	size;

	str = NULL;
	while (i < argc)
	{
		array = ft_split_strchr(argv[i], SPACE, &size);
		check_malloc(array);
		if (size == 0)
		{
			free(array);
			i++;
			continue ;
		}
		str = append_to_str(array, str);
		ft_free2((void **)array, size);
		i++;
	}
	return (str);
}

static void	check_inputfile_options(t_vars *v, char **argv, int i, char **str)
{
	if (v->opt.instr)
	{
		if (!argv[i + 1] || argv[i + 2])
			ft_exit(ERROR);
		file_option(v, argv, i, str);
		cmd_file_option(v, argv, i + 1);
	}
	else
	{
		if (argv[i + 1])
			ft_exit(ERROR);
		file_option(v, argv, i, str);
	}
}

void	check_args(t_vars *v, int argc, char **argv)
{
	char	*str;
	int		i;

	if (argc < 2)
		ft_exit(NULL);
	i = search_options(v, argc, argv);
	if (!argv[i])
		ft_exit(NULL);
	str = NULL;
	if (v->opt.file)
		check_inputfile_options(v, argv, i, &str);
	else if (v->opt.instr)
	{
		if (!argv[i + 1])
			ft_exit(NULL);
		cmd_file_option(v, argv, i);
		str = args_to_str(argc, argv, i + 1);
	}
	else
		str = args_to_str(argc, argv, i);
	if (!str)
		ft_exit(ERROR);
	v->args.args = ft_split_strchr(str, SPLIT_CHARS, &v->args.size);
	check_malloc(v->args.args);
	free(str);
}
