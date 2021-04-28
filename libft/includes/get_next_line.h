/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/16 12:21:25 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/04/07 11:26:20 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

typedef struct s_fd
{
	int		fd;
	char	*str;
}	t_fd;

int		ft_getline(int fd, char **line);
int		get_next_line(int fd, char **line);

#endif
