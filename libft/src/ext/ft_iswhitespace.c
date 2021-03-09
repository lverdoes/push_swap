/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_iswhitespace.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/09 15:28:04 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/02/26 15:22:14 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_iswhitespace(int c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}