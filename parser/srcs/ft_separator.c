/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_separator.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/15 10:23:23 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/09/05 14:02:32 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_parser.h"

static void	ft_win_line(t_parse *p)
{
	p->len += 2;
	p->str = ft_realloc(p->str, p->len);
	p->ident = ft_realloc(p->ident, p->len);
	ft_add_space(p);
}

/*
** on gagne quelques lignes
*/

static int	ft_get_hdoc(t_parse *p)
{
	int		tmp;

	tmp = p->j;
	while (p->j != 0 && ft_isdigit(p->str[p->j - 1])
		&& p->ident[p->j - 1] == REDIR)
	{
		p->j--;
		p->ident[p->j] = WORD;
	}
	p->j = tmp;
	ft_end_while(p, HEREDOC);
	ft_end_while(p, HEREDOC);
	ft_add_space(p);
	while (ft_is_white(p->s[p->i]))
		p->i++;
	if (!p->s[p->i] || ft_is_redirection(p->s[p->i]))
		return (-1);
	p->nb_hdoc++;
	return (1);
}

static int	ft_suite_sep(t_parse *p)
{
	while (ft_isdigit(p->s[p->i]))
		ft_end_while(p, REDIR);
	if (p->s[p->i] == '<' && p->s[p->i + 1] && p->s[p->i + 1] == '<')
	{
		if (ft_get_hdoc(p) == -1)
			return (-1);
		return (1);
	}
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
	ft_win_line(p);
	if (p->s[p->i] == ';')
	{
		if (ft_is_redirection(p->s[p->i + 1]))
			return (-1);
		ft_end_while(p, SEMICOLON);
	}
	else if (p->s[p->i] == '|')
	{
		if (ft_is_redirection(p->s[p->i + 1]))
			return (-1);
		ft_end_while(p, PIPE);
	}
	else if (ft_isdigit(p->s[p->i]) || p->s[p->i] == '<' || p->s[p->i] == '>')
	{
		if ((p->err = ft_suite_sep(p)) < 1)
			return (p->err);
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
