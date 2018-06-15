/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_is_separator.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/15 10:15:12 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/15 11:02:46 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_parser.h"

static int		ft_is_redirection(char c)
{
	if (c == ';')
		return (1);
	else if (c == '|')
		return (1);
	else if (c == '&')
		return (1);
	else if (c == '<')
		return (1);
	else if (c == '>')
		return (1);
	else
		return (0);
}

int			ft_is_separator(t_parse *p)
{
	if (p->str[p->j] != -1)
	{
		if (ft_is_redirection(p->s[p->i]))
			return (1);
		else
			return (0);
	}
	else
	{
		if (ft_isdigit(p->s[p->i]) && ft_is_redirection(p->s[p->i + 1]))
			return (1);
		else
			return (0);
	}
}
