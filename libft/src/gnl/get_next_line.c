/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 15:51:49 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/02/26 15:35:57 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <unistd.h>

static int	free_node(t_node **head, t_node *node, int ret)
{
	t_fd	*file;

	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
	if (node == *head && !node->next)
		*head = NULL;
	else if (node == *head && node->next)
		*head = node->next;
	file = node->content;
	ft_free(file->str);
	ft_free(file);
	ft_free(node);
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
		return (-1);
	ret = read(fd, buffer, BUFFER_SIZE);
	if (ret < 0)
		return (ft_free_int(buffer, -1));
	buffer[ret] = '\0';
	file->str = ft_append(file->str, buffer);
	ft_free(buffer);
	if (!file->str)
		return (-1);
	return (ret);
}

static t_node	*find_fd(t_node **head, t_node *node, int fd)
{
	t_fd	*tmp;

	while (node)
	{
		tmp = node->content;
		if (tmp->fd == fd)
			return (node);
		node = node->next;
	}
	tmp = ft_calloc(1, sizeof(t_fd));
	if (!tmp)
		return (NULL);
	tmp->fd = fd;
	tmp->str = ft_strdup("");
	if (!tmp->str)
		return (ft_free_ptr(tmp));
	node = ft_node_new(tmp);
	if (!node)
	{
		ft_free(tmp->str);
		return (ft_free_ptr(tmp));
	}
	ft_node_add_front(head, node);
	return (node);
}

int	get_next_line(int fd, char **line)
{
	static t_node	*head = NULL;
	int				ret;
	t_node			*node;
	t_fd			*file;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	node = find_fd(&head, head, fd);
	if (!node)
		return (-1);
	file = node->content;
	ret = 1;
	while (ret > 0 && !ft_strchr(file->str, '\n'))
		ret = read_file(fd, file);
	if (ret < 0)
		return (free_node(&head, node, -1));
	*line = ft_substr(file->str, 0, ft_substrlen(file->str, "\n"));
	if (!*line)
		return (free_node(&head, node, -1));
	file->str = reset_ptr(file->str);
	if (ret == 0)
		return (free_node(&head, node, 0));
	return (1);
}
