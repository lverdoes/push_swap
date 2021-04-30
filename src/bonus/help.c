/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   help.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/30 13:23:14 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/05/01 00:31:35 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

int	option_help(void)
{
	printf("\nList of available options:\n");
	printf("\n");
	printf("-h\thelp menu\n");
	printf("-d\tdisplay instruction frequency after sorting (checker)\n");
	printf("-v\tdisplay stacks after each instruction (checker)\n");
	printf("-c\tdisplays output in colors\n");
	printf("-f\tuse one file with integers as input\n");
	printf("-o\twith push_swap: output instructions are written to a file\n");
	printf("\twith checker: instructions are read from a file and executed\n");
	printf("\tif both -f and -o are on (-fo, -f -o), -f is the first file \n");
	printf("\n\nEx.:\t./push_swap -cf file | ./checker -cdfv file\n");
	printf("\n\n\tProject:\tpush_swap\n\tCreated by:\tlverdoes\n\n");
	ft_exit(NULL);
	return (0);
}
