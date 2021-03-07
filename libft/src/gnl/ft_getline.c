/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_getline.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/14 22:45:17 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/02/26 15:35:35 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <unistd.h>

static int	read_file(int fd, char **line)
{
	int		ret;
	char	*buffer;

	buffer = ft_calloc((size_t)BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (-1);
	ret = read(fd, buffer, BUFFER_SIZE);
	if (ret > 0)
	{
		buffer[ret] = '\0';
		*line = ft_append(*line, buffer);
		if (!*line)
			return (ft_free_int(buffer, -1));
	}
	ft_free(buffer);
	if (ret < 0)
		return (ft_free_int(line, -1));
	return (ret);
}

int	ft_getline(int fd, char **line)
{
	int		ret;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	*line = ft_strdup("\0");
	if (!*line)
		return (-1);
	ret = 1;
	while (ret > 0)
		ret = read_file(fd, line);
	return (ret);
}
