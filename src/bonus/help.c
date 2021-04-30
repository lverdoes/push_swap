/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   help.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 13:23:14 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/30 14:00:30 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

int	option_help(t_vars *v)
{
	printf("\nList of available options:\n");
	printf("\n");
	printf("-h\thelp menu\n");
	printf("-d\tprint data about instructions after sorting is done\n");
	printf("-v\tdisplay stacks after each instruction\n");
	printf("-c\tgives output colors\n");
	printf("-f\tuse a file with integers as input\n");
	printf("-o\twith push_swap: instructions are written to a file\n");
	printf("\twith checker: instructions are read from a file\n");
	printf("\tif both -f and -o are on, -f is the first file, -o the second\n");
	ft_exit(NULL);
	(void)v;
	return (0);
}
