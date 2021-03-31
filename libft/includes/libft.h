/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 16:38:16 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/03/31 16:22:16 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include "sys/types.h"

/*		./mandatory/	*/

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);

/*		./lst/		*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstclear(t_list **alst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
t_list	*ft_lstfind(t_list *list, void *data_ref, int (*cmp)());
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);

/*		./added/	*/

char	*ft_append(char *s1, const char *s2);
size_t	ft_array_size(char **array);
char	**ft_arraydup(char **array, size_t size);
double	ft_atod(const char *str);
char	*ft_concat_array(char **array, char *delim);
size_t	ft_counter(const char *s, const char *set);
void	*ft_free_ptr(void *ptr);
char	**ft_free_char(char **array, size_t i);
int		ft_free(void *ptr);
int		ft_free_int(void *ptr, int ret);
int		ft_free_array(void **array, size_t i);
int		*ft_intdup(int *src, size_t len);
int		ft_iswhitespace(int c);
void	ft_print_array(char **array);
void	ft_print_int_array(int *array, size_t size);
char	**ft_realloc(char **src, const char *line, size_t *size);
char	*ft_replace(char *s1, const char *s2, char *ptr, size_t ptr_len);
char	**ft_split_strchr(const char *s, const char *set, size_t *size);
char	**ft_split_strnstr(const char *src, const char *set, size_t *size);
int		ft_str_contains_none(const char *str, const char *set);
int		ft_str_contains_only(const char *str, const char *set);
void	ft_str_to_lower(char *str);
void	ft_str_to_upper(char *str);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strxjoin(const char *src, ...);
size_t	ft_substrlen(const char *str, const char *set);
void	ft_swap(void *a, void *b, size_t size_of_data_type);
int		ft_unique_chars(const char *str);

/*		./gnl/		*/

int		ft_getline(int fd, char **line);
int		get_next_line(int fd, char **line);

/*		./node/		*/

typedef struct s_node
{
	void			*content;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

void	ft_node_add_back(t_node **head, t_node *new_node);
void	ft_node_add_front(t_node **head, t_node *new_node);
void	ft_node_del_all(t_node **head, void (*del)(void *));
void	ft_node_del_one(t_node *node, void (*del)(void *));
t_node	*ft_node_dup(t_node *head, void *data_ref, \
		int (*cmp)(), void *(*dup)(void *), void (*del)(void *));
t_node	*ft_node_find(t_node *start, void *data_ref, int (*cmp)());
void	ft_node_insert_after(t_node **head, t_node *node, t_node *after_this);
void	ft_node_insert_before(t_node **head, t_node *node, t_node *before_this);
void	ft_node_insert_sort(t_node **head, t_node *node, int (*cmp)());
int		ft_node_is_sorted(t_node **head, int (*cmp)());
void	ft_node_iter(t_node *node, void (*f)(void *));
size_t	ft_node_index(t_node *start, t_node *node);
void	ft_node_join(t_node *left, t_node *right);
t_node	*ft_node_last(t_node *node);
void	ft_node_merge(t_node **head, t_node *right, int (*cmp)());
t_node	*ft_node_new(void *content);
t_node	*ft_node_number(t_node *node, size_t number);
void	ft_node_remove_if(t_node **head, void *data_ref, \
		int (*cmp)(), void (*del)(void *));
void	ft_node_remove_one(t_node **head, t_node *node, void (*del)(void *));
size_t	ft_node_size(t_node *node);
void	ft_node_sort(t_node *head, int (*cmp)());
void	ft_node_unlink(t_node **head, t_node *node);
void	ft_print_node_list(t_node *node, void (*print)());

#endif
