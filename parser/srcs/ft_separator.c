/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_separator.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/15 10:23:23 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/15 10:55:20 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_parser.h"

int			ft_separator(t_parse *p)
{
	p->len += 2;
	p->str = ft_realloc(p->str, p->len);
	p->ident = ft_realloc(p->ident, p->len);
	p->str[p->j] = -1;
	p->ident[p->j] = -1;
	p->j++;
	if (p->s[p->i] == ';')
		ft_end_while(p, 2);
	else if (p->s[p->i] == '|')
	{
		ft_end_while(p, 2);
		if (p->s[p->i] == '|')
			ft_end_while(p, 2);
	}
	else if (p->s[p->i] == '&' && p->s[p->i + 1] == '&')
	{
		ft_end_while(p, 2);
		ft_end_while(p, 2);
	}
	else if ((p->s[p->i] == '<' || p->s[p->i] == '>') && p->s[p->i + 1] == p->s[p->i])
	{
		ft_end_while(p, 2);
		ft_end_while(p, 2);
	}
	else
	{
		if (ft_isdigit(p->s[p->i]))
			ft_end_while(p, 2);
		if (p->s[p->i] == '<' || p->s[p->i] == '>')
			ft_end_while(p, 2);
		if (p->s[p->i] == '<' || p->s[p->i] == '>')
			ft_end_while(p, 2);
		if (p->s[p->i] == '&')
			ft_end_while(p, 2);
		if ((p->s[p->i] <= '9' && p->s[p->i] >= '0') || p->s[p->i] == '-')
			ft_end_while(p, 2);
	}
	p->str[p->j] = -1;
	p->ident[p->j] = -1;
	p->j++;
	return (1);
}
