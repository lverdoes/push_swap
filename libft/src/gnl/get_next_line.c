/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/26 13:11:35 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/05/26 13:11:41 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "ft_list.h"
#include "libft.h"
#include "ft_ext.h"
#include <unistd.h>

static int	free_list(t_list **head, t_list *list, int ret)
{
	t_fd	*file;

	if (list->prev)
		list->prev->next = list->next;
	if (list->next)
		list->next->prev = list->prev;
	if (list == *head && !list->next)
		*head = NULL;
	else if (list == *head && list->next)
		*head = list->next;
	file = list->content;
	ft_free(file->str);
	ft_free(file);
	ft_free(list);
	return (ret);
}

static char	*reset_ptr(char *str)
{
	char	*next_line_start;
	char	*ptr;

	ptr = ft_strchr(str, '\n');
	if (!ptr)
		return (str);
	next_line_start = ft_strdup(ptr + 1);
	ft_free(str);
	return (next_line_start);
}

static int	read_file(int fd, t_fd *file)
{
	int		ret;
	char	*buffer;

	buffer = ft_calloc((size_t)BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (GNL_ERROR);
	ret = read(fd, buffer, BUFFER_SIZE);
	if (ret < 0)
	{
		ft_free(buffer);
		return (GNL_ERROR);
	}
	buffer[ret] = '\0';
	file->str = ft_append(file->str, buffer);
	ft_free(buffer);
	if (!file->str)
		return (GNL_ERROR);
	return (ret);
}

static t_list	*find_fd(t_list **head, t_list *list, int fd)
{
	t_fd	*tmp;

	while (list)
	{
		tmp = list->content;
		if (tmp->fd == fd)
			return (list);
		list = list->next;
	}
	tmp = ft_calloc(1, sizeof(t_fd));
	if (!tmp)
		return (NULL);
	tmp->fd = fd;
	tmp->str = ft_strdup("");
	if (!tmp->str)
		return (ft_free(tmp));
	list = ft_list_new(tmp);
	if (!list)
	{
		ft_free(tmp->str);
		return (ft_free(tmp));
	}
	ft_list_add_front(head, list);
	return (list);
}

int	get_next_line(int fd, char **line)
{
	static t_list	*head = NULL;
	int				ret;
	t_list			*list;
	t_fd			*file;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE < 1 || !line)
		return (GNL_ERROR);
	list = find_fd(&head, head, fd);
	if (!list)
		return (GNL_ERROR);
	file = list->content;
	ret = 1;
	while (ret > 0 && !ft_strchr(file->str, '\n'))
		ret = read_file(fd, file);
	if (ret < 0)
		return (free_list(&head, list, GNL_ERROR));
	*line = ft_substr(file->str, 0, ft_substrlen(file->str, "\n"));
	if (!*line)
		return (free_list(&head, list, GNL_ERROR));
	file->str = reset_ptr(file->str);
	if (ret == GNL_END)
		return (free_list(&head, list, GNL_END));
	return (GNL_LINE);
}
