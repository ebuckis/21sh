/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_separator.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/15 10:23:23 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/18 15:11:31 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_parser.h"

static void	ft_double_end(t_parse *p)
{
	ft_end_while(p, 2);
	ft_end_while(p, 2);
}

/*
** on gagne quelques lignes
*/

static void	ft_suite_sep(t_parse *p)
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

/*
** Petit parsing pour les redirections
** Peut poser des problemes, sans dout a revoir
*/

int			ft_separator(t_parse *p)
{
	p->len += 2;
	p->str = ft_realloc(p->str, p->len);
	p->ident = ft_realloc(p->ident, p->len);
	ft_add_space(p);
	if (p->s[p->i] == ';')
		ft_end_while(p, 2);
	else if (p->s[p->i] == '|')
	{
		ft_end_while(p, 2);
		if (p->s[p->i] == '|')
			ft_end_while(p, 2);
	}
	else if (p->s[p->i] == '&' && p->s[p->i + 1] == '&')
		ft_double_end(p);
	else if ((p->s[p->i] == '<' || p->s[p->i] == '>')
		&& p->s[p->i + 1] == p->s[p->i])
		ft_double_end(p);
	else
		ft_suite_sep(p);
	ft_add_space(p);
	return (1);
}

/*
** On realloue de la memoire pour ajouter des espaces au cas ou
** la redirection ne soit par marquée par des espaces
*/
