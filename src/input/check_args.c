/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_args.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/03 23:23:16 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/05 17:59:17 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	check_args(t_args *a, int argc, char **argv)
{
	int		i;
	size_t	size;
	char	**array;
	char	*str;

	if (argc < 2)
		ft_exit(NULL);
	str = NULL;
	i = 1;
	while (i < argc)
	{
		array = ft_split_strchr(argv[i], " ", &size);
		check_malloc(array);
		str = append_to_str(array, str);
		ft_free_array((void **)array, size);
		i++;
	}
	a->args = ft_split_strchr(str, " ", &a->size);
	check_malloc(a->args);
	ft_free(str);
}
