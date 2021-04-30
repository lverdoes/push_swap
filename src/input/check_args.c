/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_args.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 23:23:16 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/30 17:08:38 by lverdoes      ########   odam.nl         */
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

void	check_args(t_vars *v, int argc, char **argv)
{
	char	*str;
	int		start;

	if (argc < 2)
		ft_exit(NULL);
	start = search_options(v, argc, argv);
	str = NULL;
	if (v->opt.file)
		file_option(argv, start, &str);
	else
		str = args_to_str(argc, argv, start);
	if (!argv[start])
		ft_exit(NULL);
	if (!str)
		ft_exit("Error !str");
	if (v->opt.instr)
		cmd_file_option(v, argv, start);
	v->args.args = ft_split_strchr(str, SPLIT_CHARS, &v->args.size);
	check_malloc(v->args.args);
	free(str);
}
