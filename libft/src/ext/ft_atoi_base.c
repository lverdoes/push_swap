/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/03 01:13:36 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/02/26 15:28:44 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_index(const char *base, int c)
{
	size_t	i;

	i = 0;
	while (base[i] != '\0' && base[i] != c)
		i++;
	return (i);
}

static int	check_base(const char *base, size_t *base_len)
{
	size_t	i;

	*base_len = ft_strlen(base);
	if (*base_len < 2)
		return (0);
	if (!ft_unique_chars(base))
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if (ft_iswhitespace(base[i]))
			return (0);
		if (base[i] == '-')
			return (0);
		if (base[i] == '+')
			return (0);
		i++;
	}
	return (1);
}

static int	check_sign(const char *str, size_t *i)
{
	if (str[*i] == '-')
	{
		*i += 1;
		return (-1);
	}
	if (str[*i] == '+')
		*i += 1;
	return (1);
}

int	ft_atoi_base(const char *str, const char *base)
{
	size_t	base_len;
	size_t	i;
	int		neg;
	long	result;
	size_t	j;

	if (!check_base(base, &base_len))
		return (0);
	i = 0;
	while (ft_iswhitespace(str[i]))
		i++;
	neg = check_sign(str, &i);
	if (!ft_str_contains_only(str + i, base))
		return (0);
	result = 0;
	while (str[i] != '\0')
	{
		j = check_index(base, str[i]);
		result = result * base_len + j;
		i++;
	}
	result = result * neg;
	return (result);
}
