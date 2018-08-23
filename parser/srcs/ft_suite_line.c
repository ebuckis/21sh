/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_suite_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kcabus <kcabus@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/15 13:54:21 by kcabus       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/23 15:50:36 by kcabus      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_parser.h"

int			ft_suite_line(t_parse *p, int i, char *prompt)
{
	char	*tmp;

	tmp = NULL;
	if (i == 0)
		p->i++;
	if (i == 1)
	{
		i = 2;
		if (!(p->s = ft_strjoin_del(p->s, "\n")))
			return (0);
	}
	tmp = ft_edition(prompt);
	if (g_nav.err == SIG_CTRLD)
		return (0);
	if (!tmp)
		return (1);
	if (!(p->s = ft_strjoin_del(p->s, tmp)))
		return (0);
	if (ft_strlen(tmp) != 0 || i != 0)
	{
		p->len += i + ft_strlen(tmp);
		p->str = ft_realloc(p->str, p->len);
		p->ident = ft_realloc(p->ident, p->len);
		if (!p->str || !p->ident)
			return (0);
	}
	free(tmp);
	return (1);
}

/*
** Permet de lire de nouveau sur l'entrée stantdard
** Reallocation de memoire nécessaire
*/

void		ft_end_while(t_parse *p, char c)
{
	p->str[p->j] = p->s[p->i];
	p->ident[p->j] = c;
	p->i++;
	p->j++;
}

/*
** Incrementation standard
*/

void		ft_add_space(t_parse *p)
{
	p->str[p->j] = -1;
	p->ident[p->j] = -1;
	p->j++;
}

/*
** Marque un 'espace' grace au char -1 qui permettra de spliter plus loin
*/
