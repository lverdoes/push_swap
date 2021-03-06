/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_iswhitespace.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lverdoes <lverdoes@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/09 15:28:04 by lverdoes      #+#    #+#                 */
/*   Updated: 2021/05/27 18:06:52 by lverdoes      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_iswhitespace(int c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}
