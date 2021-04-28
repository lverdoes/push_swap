/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_args.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 23:23:16 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/27 18:11:43 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "ft_ext.h"

static char	*append_to_str(char **array, char *str)
{
	char	*substr;

	substr = ft_concat_array(array, " ");
	check_malloc(substr);
	str = ft_append(str, " ");
	check_malloc(str);
	str = ft_append(str, substr);
	check_malloc(str);
	ft_free(substr);
	return (str);
}

static char	*args_to_str(int argc, char **argv)
{
	char	*str;
	char	**array;
	size_t	size;
	int		i;

	str = NULL;
	i = 1;
	while (i < argc)
	{
		array = ft_split_strchr(argv[i], " ", &size);
		check_malloc(array);
		if (size == 0)
		{
			ft_free(array);
			i++;
			continue ;
		}
		str = append_to_str(array, str);	
		ft_free2((void **)array, size);
		i++;
	}
	return (str);
}

void	check_args(t_args *a, int argc, char **argv)
{
	char	*str;

	if (argc < 2)
		ft_exit(NULL);
	str = args_to_str(argc, argv);
	if (!str)
		ft_exit(NULL);
	a->args = ft_split_strchr(str, " ", &a->size);
	check_malloc(a->args);
	ft_free(str);
}
