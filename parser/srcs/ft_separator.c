/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_separator.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/15 10:23:23 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/20 13:18:40 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_parser.h"

static void	ft_double_end(t_parse *p)
{
	ft_end_while(p, 2);
	ft_end_while(p, 2);
}//inutilisee

/*
** on gagne quelques lignes
*/

static int	ft_get_hdoc(t_parse *p)
{
	ft_end_while(p, HEREDOC);
	ft_end_while(p, HEREDOC);
	ft_add_space(p);
	while (ft_is_white(p->s[p->i]))
		p->i++;
	if (ft_is_redirection(p->s[p->i]))
		return (-1);
	while (p->s[p->i] && !ft_is_redirection(p->s[p->i])
		&& !ft_is_white(p->s[p->i]))
		ft_end_while(p, HEREDOC);
	ft_add_space(p);
	return (1);
}

static int	ft_suite_sep(t_parse *p)
{
	if (ft_isdigit(p->s[p->i]))
		ft_end_while(p, REDIR);
	if (p->s[p->i] == '<' || p->s[p->i] == '>')
		ft_end_while(p, REDIR);
	else
		return (-1);
	if (p->s[p->i] == '<' || p->s[p->i] == '>')
		ft_end_while(p, REDIR);
	if (p->s[p->i] == '&')
		ft_end_while(p, REDIR);
	if (!p->s[p->i])
		return (-1);
	if ((p->s[p->i] <= '9' && p->s[p->i] >= '0') || p->s[p->i] == '-')
		ft_end_while(p, REDIR);
	return (1);
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
	{
		if (ft_is_redirection(p->s[p->i + 1]))
			return (-1);//parse error
		ft_end_while(p, SEMICOLON);
	}
	else if (p->s[p->i] == '<' && p->s[p->i + 1] && p->s[p->i + 1] == '<')
	{
		if (ft_get_hdoc(p) == -1)
			return (-1);
	}
	else if (p->s[p->i] == '|')
	{
		if (ft_is_redirection(p->s[p->i + 1]))
			return (-1);//parse error
		ft_end_while(p, PIPE);
	}
	else if (p->s[p->i] == '&')
	{
		return (-1);// a revoir
	}
	else if (ft_isdigit(p->s[p->i]) || p->s[p->i] == '<' || p->s[p->i] == '>')
	{
		if (ft_suite_sep(p) < 1)
			return (-1);//parse error
	}
	else
		return (-1);
	ft_add_space(p);
	return (1);
}

/*
** On realloue de la memoire pour ajouter des espaces au cas ou
** la redirection ne soit par marquée par des espaces
*/
