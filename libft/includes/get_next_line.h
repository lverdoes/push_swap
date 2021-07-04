/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/16 12:21:25 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/05/26 12:57:37 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

enum e_return_value
{
	GNL_ERROR = -1,
	GNL_END = 0,
	GNL_LINE = 1
};

typedef struct s_filedescriptor
{
	int		fd;
	char	*str;
}	t_fd;

int		ft_getfile(int fd, char **str);
int		get_next_line(int fd, char **line);

#endif
